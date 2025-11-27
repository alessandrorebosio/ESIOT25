#include <Arduino.h>

#include "core/Context.h"
#include "core/Scheduler.h"

#include "model/Hardware.h"
#include "model/system/HWSystem.h"

#include "tasks/BlinkTask.h"
#include "tasks/SystemTask.h"

static Scheduler scheduler;
static Context context;
static Hardware hw;

void setup() {
    scheduler.init(100);
    hw.init();

    scheduler.addTask(new SystemTask(hw.getButton(), hw.getLed1(), hw.getTempSensor(), context, 1000));
    scheduler.addTask(new BlinkTask(hw.getLed3(), context.shouldBlink(), 500));
}

void loop() {
    scheduler.schedule();
}
