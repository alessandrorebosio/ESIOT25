#include <Arduino.h>

#include "core/Scheduler.h"

Scheduler scheduler;

void setup() {
    scheduler.init(100);

    scheduler.addTask(NULL);
}

void loop() {
    scheduler.schedule();
}
