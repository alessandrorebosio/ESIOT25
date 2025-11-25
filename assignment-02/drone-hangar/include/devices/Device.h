#pragma once

#include <Arduino.h>

class Device {
  protected:
    uint8_t pin;

  public:
    explicit Device(uint8_t pin) : pin(pin) {
    }

    void begin(uint8_t mode) const {
        pinMode(pin, mode);
    }

    int read() const {
        return digitalRead(pin);
    }

    void write(uint8_t val) const {
        digitalWrite(pin, val);
    }

    uint8_t getPin() const {
        return this->pin;
    }

    virtual ~Device() = default;
};