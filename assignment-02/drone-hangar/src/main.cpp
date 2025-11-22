#include <Arduino.h>

#include "core/Scheduler.h"

#include "model/HWPlatform.h"

#include "tasks/BlinkingTask.h"

#include "config.h"

Scheduler scheduler;
HWPlatform *hw;

void setup() {
    hw = new HWPlatform();

    scheduler.init(100);
}

void loop() {
    scheduler.schedule();
}
