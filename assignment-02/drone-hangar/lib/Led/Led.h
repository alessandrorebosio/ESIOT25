#pragma once

#include "Device/Light.h"

class Led : public Light {
  private:
    uint8_t pin;

  public:
    Led(uint8_t pin) : pin(pin) { this->begin(); }

    void begin() override;

    void on() override;

    void off() override;
};
