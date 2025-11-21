#pragma once

#include "Device.h"

class Light : public Device {
  public:
    explicit Light(uint8_t pin) : Device(pin) {
    }

    virtual void on() = 0;

    virtual void off() = 0;
};