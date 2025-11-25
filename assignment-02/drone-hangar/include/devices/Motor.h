#pragma once

#include "Device.h"

class Motor : public Device {
  public:
    explicit Motor(uint8_t pin) : Device(pin) {
    }

    virtual void on() = 0;

    virtual void off() = 0;

    virtual void setPosition(short angle) = 0;

    virtual ~Motor() = default;
};
