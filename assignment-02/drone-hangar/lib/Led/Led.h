#ifndef LED_H
#define LED_H

#include "../../include/devices/Light.h"

class Led : public Light {
  private:
    uint8_t pin;

  public:
    Led(uint8_t pin) : pin(pin) { this->begin(); }

    void begin() override;

    void on() override;

    void off() override;
};

#endif