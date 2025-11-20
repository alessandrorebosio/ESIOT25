#pragma once

#include <Arduino.h>

class TempSensor {
  public:
    virtual float getTemperature() = 0;
};
