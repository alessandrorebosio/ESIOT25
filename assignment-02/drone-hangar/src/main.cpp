#include <Arduino.h>

#include <Led.h>

#include "core/MsgService.h"
#include "core/Scheduler.h"

#include "model/Context.h"
#include "model/HWPlatform.h"

#include "tasks/BlinkingTask.h"
#include "tasks/SystemTask.h"

#include "config.h"

static Scheduler scheduler;

void setup() {
    HWPlatform *hw = new HWPlatform(new MsgService(BAUD));
    Context *context = new Context();
    scheduler.init(BASEPERIOD);

    scheduler.addTask(new SystemTask(hw, context, BASEPERIOD * 10));
    scheduler.addTask(
        new BlinkingTask(hw, context, BASEPERIOD * 5));
}

void loop() {
    scheduler.schedule();
}
