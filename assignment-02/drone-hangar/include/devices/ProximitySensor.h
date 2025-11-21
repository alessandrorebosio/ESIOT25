#pragma once

#include <Arduino.h>

class ProximitySensor {
  public:
    virtual void begin() = 0;

    virtual void setTemperature(const float temperature) = 0;

    virtual float getDistance() = 0;

    virtual int equals(int value) = 0;
};
