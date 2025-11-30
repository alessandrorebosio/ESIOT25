#include <Arduino.h>

#include "core/Context.h"
#include "core/Message.h"
#include "core/Scheduler.h"

#include "model/Hardware.h"

#include "tasks/BlinkTask.h"
#include "tasks/FlightTask.h"
#include "tasks/GateTask.h"
#include "tasks/ObserverTask.h"
#include "tasks/SystemTask.h"

#include "config.h"

static Scheduler scheduler;
static Message message;
static Context context;
static Hardware hw;

void setup(void) {
    scheduler.init(100);
    message.init(BAUD);
    hw.init();

    scheduler.addTask(new System::SystemTask(new HWSystem(hw.getButton(), hw.getLed1(), hw.getLed3(), hw.getTempSensor()), context, 1000));
    scheduler.addTask(new Flight::FlightTask(new HWFlight(hw.getPir(), hw.getSonar(), hw.getTempSensor()), context, context.isFlightAllowed(), 500));
    scheduler.addTask(new Blink::BlinkTask(new HWBlink(hw.getLed2()), context.shouldBlink(), 500));
    scheduler.addTask(new Gate::GateTask(new HWGate(hw.getMotor()), context.shouldOpen(), 20));

    scheduler.addTask(new Observer::ObserverTask(true, [] { message.send("T: " + String(hw.getTempSensor().readTemperature())); }, 1000));
    scheduler.addTask(new Observer::ObserverTask(
        true,
        [] {
            hw.getSonar().setTemperature(hw.getTempSensor().readTemperature());
            message.send("D: " + String(hw.getSonar().readDistance()));
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
        500));
}

void loop(void) {
    message.read();
    scheduler.schedule();
    message.clear();
}
