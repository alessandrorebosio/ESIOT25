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

void setup() {
    scheduler.init(100);
    msg.init(BAUD);
    hw.init();

    // scheduler.addTask(new System::SystemTask(new HWSystem(hw.getButton(), hw.getLed1(), hw.getTempSensor()), context, msg, 1000));
    // // scheduler.addTask(new Flight::FlightTask(new HWFlight(hw.getPir(), hw.getSonar(), hw.getTempSensor(), hw.getLcd()), context, msg, false,
    // 200));
    // // scheduler.addTask(new Check::CheckTask(new HWCheck(hw.getSonar(), hw.getTempSensor(), hw.getLcd()), context, msg, false, 500));
    // scheduler.addTask(new Blink::BlinkTask(new HWBlink(hw.getLed3()), context.shouldBlink(), 500));
    // scheduler.addTask(new Gate::GateTask(new HWGate(hw.getMotor()), context.shouldOpen(), 20));
    scheduler.addTask(new Observer::ObserverTask(
        &context, &Context::isOperationDone,
        [] {
            msg.send("ok");
            context.doLanding();
        },
        1000));
}

void loop() {
    scheduler.schedule();
}
