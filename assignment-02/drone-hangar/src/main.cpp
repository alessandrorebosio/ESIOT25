#include <Arduino.h>

#include "core/Scheduler.h"

#include "model/HWPlatform.h"

#include "tasks/BlinkingTask.h"
#include "tasks/SerialMonitorTask.h"

#include "config.h"

SerialMonitorTask *serialMonitor;
Scheduler scheduler;
HWPlatform *hw;

void setup() {
    serialMonitor = new SerialMonitorTask(BAUD, 100);
    hw = new HWPlatform();

    scheduler.init(100);

    scheduler.addTask(serialMonitor);
    scheduler.addTask(new BlinkingTask(hw->getLed(-1), 1000));
}

void loop() {
    scheduler.schedule();
}
