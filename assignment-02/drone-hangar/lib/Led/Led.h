#pragma once

#include "devices/Light.h"

class Led final : public Light {
  public:
    explicit Led(uint8_t pin);

    void on() override;

    void off() override;
};
