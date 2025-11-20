#include <Arduino.h>

#include "model/HWPlatform.h"

#include "config.h"

HWPlatform *hw;

void setup() {
    hw = new HWPlatform();
}

void loop() {}
