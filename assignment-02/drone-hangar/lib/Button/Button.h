#pragma once

#include "devices/Switch.h"

class Button final : public Switch {
  private:
    unsigned long lastTime = 0;
    uint8_t lastReading = LOW;
    uint8_t rawReading = LOW;

  public:
    explicit Button(const uint8_t pin);

    bool isPressed() override;
};
