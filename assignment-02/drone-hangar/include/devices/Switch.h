#pragma once

#include "Device.h"

class Switch : public Device {
  public:
    explicit Switch(uint8_t pin) : Device(pin) {
    }

    virtual bool isPressed() = 0;

    virtual ~Switch() = default;
};
