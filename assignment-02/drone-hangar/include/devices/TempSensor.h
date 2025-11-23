#pragma once

#include "Device.h"

class TempSensor : public Device {
  public:
    explicit TempSensor(uint8_t pin) : Device(pin) {
    }

    virtual float getTemperature() = 0;
};
