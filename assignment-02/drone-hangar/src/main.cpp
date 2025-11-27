#include <Arduino.h>

#include "core/Scheduler.h"
#include "core/Context.h"

static Scheduler scheduler(100);
static Context context;

void setup() {
    scheduler.addTask(nullptr);
}

void loop() {
    scheduler.schedule();
}
