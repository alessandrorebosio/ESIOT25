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
#include "tasks/OperatingTask.h"
#include "tasks/SystemTask.h"

#include "config.h"

static Hardware hw(BTN_PIN, L1_PIN, L2_PIN, L3_PIN, SERVO_PIN, PIR_PIN, SNR_TRIG_PIN, SNR_TRIG_PIN, MAXTIME, TMP_PIN, LCD_ADDR, LCD_COLS, LCD_ROWS);
static Scheduler scheduler;
static Message message;
static Context context;

void setup(void) {
    scheduler.init(100);
    message.init(BAUD);
    hw.init();

    scheduler.addTask(new System::SystemTask(HardwareFactory::createHWSystem(hw), context, 1000));
    scheduler.addTask(new Flight::FlightTask(HardwareFactory::createHWFlight(hw), context, context.isFlightAllowed(), 400));
    scheduler.addTask(new Operating::OperatingTask(HardwareFactory::createHWOperating(hw), context, 200));

    scheduler.addTask(new Blink::BlinkTask(HardwareFactory::createHWBlink(hw), context.shouldBlink(), 500));
    scheduler.addTask(new Gate::GateTask(HardwareFactory::createHWGate(hw), context.shouldOpen(), 20));

    scheduler.addTask(new Observer::ObserverTask(
        true,
        [] {
            message.send("T: " + String(HardwareFactory::measureTemperature(hw)));
            message.send("D: " + String(HardwareFactory::measureDistance(hw)));
        },
        1000));

    scheduler.addTask(new Observer::ObserverTask(
        message.isMessageAvailable(),
        [] {
            message.equalsIgnoreCase("TAKEOFF") ? context.setTakeOffMsg() : void();
            message.equalsIgnoreCase("LANDING") ? context.setLandingMsg() : void();
        },
        100));

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

void loop(void) {
    message.read();
    scheduler.schedule();
    message.clear();
}
