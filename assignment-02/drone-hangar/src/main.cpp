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

    scheduler.addTask(new BlinkingTask(hw->getLed(-1), 1000));
}

void loop() {
    scheduler.schedule();
}
