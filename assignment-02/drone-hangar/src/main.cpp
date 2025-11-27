#include <Arduino.h>

#include "core/Context.h"
#include "core/Scheduler.h"

#include "model/Hardware.h"

static Scheduler scheduler(100);
static Context context;
static Hardware hw;

void setup() {
    scheduler.addTask(nullptr);
}

void loop() {
    scheduler.schedule();
}
