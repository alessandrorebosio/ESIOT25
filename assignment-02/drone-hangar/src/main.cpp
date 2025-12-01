#include <Arduino.h>

#include "core/Context.h"
#include "core/Message.h"
#include "core/Scheduler.h"

#include "model/Hardware.h"
#include "model/HardwareFactory.h"

#include "tasks/BlinkTask.h"
#include "tasks/FlightTask.h"
#include "tasks/GateTask.h"
#include "tasks/ObserverTask.h"
#include "tasks/SystemTask.h"

#include "config.h"

/**
 * @mainpage Smart Drone Hangar
 * @section authors Authors
 * - [Alessandro Rebosio] - <alessandro.rebosio@studio.unibo.it>
 * - [Grazia Bochdanovits de Kavna] - <grazia.bochdanovits@studio.unibo.it>
 *
 * @section description Project Description
 * This project implements a drone control system with hardware abstraction,
 * task scheduling, state management, and serial communication capabilities.
 */

static Hardware hw(BTN_PIN, L1_PIN, L2_PIN, L3_PIN, SERVO_PIN, PIR_PIN, SNR_TRIG_PIN, SNR_TRIG_PIN, MAXTIME, TMP_PIN, LCD_ADDR, LCD_COLS, LCD_ROWS);
static Scheduler scheduler;
static Message message;
static Context context;

/**
 * @brief Initializes the system components and tasks.
 *
 * This function is called once at startup to:
 * 1. Initialize the scheduler with base period
 * 2. Initialize serial communication
 * 3. Initialize hardware components
 * 4. Create and add all system tasks to the scheduler
 *
 * Tasks include:
 * - SystemTask: Manages system states and alarms
 * - FlightTask: Manages drone flight operations
 * - BlinkTask: Controls LED blinking patterns
 * - GateTask: Manages gate/servo operations
 * - ObserverTasks: Monitor sensors and handle messages
 */
void setup(void) {
    scheduler.init(100);
    message.init(BAUD);
    hw.init();

    /**
     * @brief System task for managing system states and alarms.
     * Period: 1000ms
     */
    scheduler.addTask(new System::SystemTask(HardwareFactory::createHWSystem(hw), context, 1000));

    /**
     * @brief Flight task for managing drone takeoff and landing operations.
     * Period: 400ms
     */
    scheduler.addTask(new Flight::FlightTask(HardwareFactory::createHWFlight(hw), context, context.isFlightAllowed(), 400));

    /**
     * @brief Blink task for controlling LED blinking based on system state.
     * Period: 500ms
     */
    scheduler.addTask(new Blink::BlinkTask(HardwareFactory::createHWBlink(hw), context.shouldBlink(), 500));

    /**
     * @brief Gate task for controlling servo/gate operations.
     * Period: 20ms (fast for smooth servo control)
     */
    scheduler.addTask(new Gate::GateTask(HardwareFactory::createHWGate(hw), context.shouldOpen(), 20));

    /**
     * @brief Observer task for monitoring temperature and distance sensors.
     * Period: 1000ms
     * Sends sensor data via serial communication.
     */
    scheduler.addTask(new Observer::ObserverTask(
        true,
        [] {
            message.send("T: " + String(HardwareFactory::measureTemperature(hw)));
            message.send("D: " + String(HardwareFactory::measureDistance(hw)));
        },
        1000));

    /**
     * @brief Observer task for handling incoming serial messages.
     * Period: 100ms (fast for responsive message handling)
     * Processes TAKEOFF and LANDING commands.
     */
    scheduler.addTask(new Observer::ObserverTask(
        message.isMessageAvailable(),
        [] {
            message.equalsIgnoreCase("TAKEOFF") ? context.setTakeOffMsg() : void();
            message.equalsIgnoreCase("LANDING") ? context.setLandingMsg() : void();
        },
        100));

    /**
     * @brief Observer task for printing system and drone states.
     * Period: 400ms
     * Updates LCD display and sends state information via serial.
     */
    scheduler.addTask(new Observer::ObserverTask(
        context.shouldPrint(),
        [] {
            String sys = context.shouldPrintNormal()     ? "NORMAL"
                         : context.shouldPrintPreAlarm() ? "PREALARM"
                         : context.shouldPrintAlarm()    ? "ALARM"
                                                         : nullptr;
            if (sys) {
                hw.getLcd().print(0, "SYSTEM: " + sys);
                message.send(sys);
            }

            String drone = context.shouldPrintInside()    ? "INSIDE"
                           : context.shouldPrintTakeOff() ? "TAKEOFF"
                           : context.shouldPrintOutside() ? "OUTSIDE"
                           : context.shouldPrintLanding() ? "LANDING"
                                                          : nullptr;
            if (drone) {
                hw.getLcd().print(1, "DRONE: " + drone);
                message.send(drone);
            }

            context.printDone();
        },
        400));
}

/**
 * @brief Main execution loop.
 *
 * This function runs continuously and:
 * 1. Reads incoming serial messages
 * 2. Executes scheduled tasks
 * 3. Clears message buffer
 *
 * The scheduler ensures all tasks run at their specified periods
 * while maintaining system responsiveness.
 */
void loop(void) {
    message.read();
    scheduler.schedule();
    message.clear();
}
