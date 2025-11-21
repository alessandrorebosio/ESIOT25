#pragma once

#include "devices/Switch.h"

class Button : public Switch {
  private:
    unsigned long lastTime = 0;
    uint8_t lastReading = LOW;
    uint8_t rawReading = LOW;
    uint8_t pin;

  public:
    Button(const uint8_t pin) : pin(pin) {
        this->begin();
    }

    void begin() override;

    bool isPressed() override;
};
