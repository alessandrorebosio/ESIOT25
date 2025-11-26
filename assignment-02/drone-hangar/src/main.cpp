#include <Arduino.h>

#include "core/MsgService.h"
#include "core/Scheduler.h"

#include "tasks/BlinkingTask.h"
#include "tasks/CheckTask.h"
#include "tasks/SystemTask.h"

#include "model/HWPlatform.h"

static Scheduler scheduler(new Context());

void setup() {
    HWPlatform *hw = new HWPlatform(new MsgService(BAUD));
    scheduler.init(BASEPERIOD);

    scheduler.addTask(
        new SystemTask(hw, scheduler.getContext(), BASEPERIOD * 10));
    scheduler.addTask(
        new BlinkingTask(hw, scheduler.getContext(), BASEPERIOD * 5));
    scheduler.addTask(
        new CheckTask(hw, scheduler.getContext(), BASEPERIOD * 5));
}

void loop() {
    scheduler.schedule();
}
