#include <Arduino.h>

#include "core/Scheduler.h"
#include "core/MsgService.h"

#include "model/HWPlatform.h"
#include "model/Context.h"

#include "tasks/BlinkingTask.h"
#include "tasks/HangarControlTask.h"
#include "tasks/DistanceMeasuringTask.h"
#include "tasks/SweepingTask.h"

#include "config.h"

Scheduler scheduler;
HWPlatform *hw;
Context *context;
MsgSerivce *msg;

void setup() {
    hw = new HWPlatform();
    context = new Context();
    msg = new MsgSerivce(BAUD);

    Task *hangarControl = new HangarControlTask(hw, msg, context);
    hangarControl->init(DEFAULT_PERIOD);

    Task *sweepingDoor = new SweepingTask(hw->getMotor(), context);
    sweepingDoor->init(DEFAULT_PERIOD);

    Task *measuringDist = new DistanceMeasuringTask(hw->getSonar(), msg, context);
    measuringDist->init(DEFAULT_PERIOD);

    scheduler.init(DEFAULT_PERIOD);

    scheduler.addTask(hangarControl);
    scheduler.addTask(sweepingDoor);
    scheduler.addTask(measuringDist);
}

void loop() {
    scheduler.schedule();
}
