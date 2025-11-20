#include <Arduino.h>

#include "core/Scheduler.h"
#include "model/HWPlatform.h"

#include "config.h"

Scheduler scheduler;
HWPlatform *hw;

void setup() {
    scheduler.init(100);

    hw = new HWPlatform();
}

void loop() { scheduler.schedule(); }
