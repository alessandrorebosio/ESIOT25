#include <Arduino.h>

#include "core/Scheduler.h"
#include "model/HWPlatform.h"
#include "tasks/SerialMonitorTask.h"

#include "config.h"

Scheduler scheduler;
HWPlatform hw;

void setup() {
    scheduler.init(100);

    scheduler.addTask(new SerialMonitorTask(BAUD, 100));
}

void loop() {
    scheduler.schedule();
}
