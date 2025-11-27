#include <Arduino.h>

#include "core/Context.h"
#include "core/Scheduler.h"

#include "model/Hardware.h"

#include "tasks/BlinkTask.h"

#include <Led.h>

static Scheduler scheduler(100);
static Context context;

void setup() {
    Hardware hw;
    scheduler.addTask(new BlinkTask(hw.getLed3(), context.shouldBlink(), 100));
}

void loop() {
    scheduler.schedule();
}
