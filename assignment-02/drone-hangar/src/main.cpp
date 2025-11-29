#include <Arduino.h>

#include "core/Context.h"
#include "core/MsgService.h"
#include "core/Scheduler.h"

#include "model/Hardware.h"

#include "tasks/BlinkTask.h"
#include "tasks/CheckTask.h"
#include "tasks/FlightTask.h"
#include "tasks/GateTask.h"
#include "tasks/ObserverTask.h"
#include "tasks/SystemTask.h"

#include "config.h"

static Scheduler scheduler;
static MsgService msg;
static Context context;
static Hardware hw;

void setup(void) {
    scheduler.init(100);
    msg.init(BAUD);
    hw.init();

    scheduler.addTask(new System::SystemTask(new HWSystem(hw.getButton(), hw.getLed1(), hw.getLed3(), hw.getTempSensor()), context, 1000));
    scheduler.addTask(new Check::CheckTask(new HWCheck(hw.getSonar(), hw.getTempSensor()), context, context.shouldMeasure(), 1000));
    scheduler.addTask(new Blink::BlinkTask(new HWBlink(hw.getLed2()), context.shouldBlink(), 500));
    scheduler.addTask(new Gate::GateTask(new HWGate(hw.getMotor()), context.shouldOpen(), 20));

    scheduler.addTask(new Observer::ObserverTask(
        context, &Context::shouldListen,
        [] {
            msg.read();

            String m = msg.get();
            m.toUpperCase();
            if (m.equals("TAKEOFF") || m.equals("LANDING")) {
                context.startBlink();
            }
        },
        100));

    scheduler.addTask(new Observer::ObserverTask(
        context, &Context::shouldPrint,
        [] {
            String sys = context.shouldPrintNormal()     ? "NORMAL"
                         : context.shouldPrintPreAlarm() ? "PREALARM"
                         : context.shouldPrintAlarm()    ? "ALARM"
                                                         : nullptr;
            if (sys) {
                hw.getLcd().print(0, "SYSTEM: " + sys);
                msg.send(sys);
            }

            String drone = context.shouldPrintInside()    ? "INSIDE"
                           : context.shouldPrintTakeOff() ? "TAKEOFF"
                           : context.shouldPrintOutside() ? "OUTSIDE"
                           : context.shouldPrintLanding() ? "LANDING"
                                                          : nullptr;
            if (drone) {
                hw.getLcd().print(1, "DRONE: " + drone);
                msg.send(drone);
            }

            context.printDone();
        },
        500));
}

void loop(void) {
    scheduler.schedule();
    msg.clear();
}
