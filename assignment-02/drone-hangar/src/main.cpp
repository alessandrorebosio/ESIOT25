#include <Arduino.h>

#include "core/MsgService.h"
#include "core/Scheduler.h"

#include "model/Context.h"
#include "model/HWPlatform.h"

#include "tasks/BlinkingTask.h"
#include "tasks/DistanceMeasuringTask.h"
#include "tasks/HangarControlTask.h"
#include "tasks/SweepingTask.h"

#include "config.h"

Scheduler scheduler;

void setup() {
    Context *context = new Context();
    HWPlatform *hw = new HWPlatform();
    MsgSerivce *msg = new MsgSerivce(BAUD);

    scheduler.init(BASEPERIOD);

    scheduler.addTask(new HangarControlTask(hw, msg, context, BASEPERIOD * 10));
    scheduler.addTask(new BlinkingTask(hw->getL2(), BASEPERIOD * 5));
    scheduler.addTask(new SweepingTask(hw->getMotor(), context, BASEPERIOD));
    scheduler.addTask(
        new DistanceMeasuringTask(hw->getSonar(), msg, context, BASEPERIOD));
}

void loop() {
    scheduler.schedule();
}
