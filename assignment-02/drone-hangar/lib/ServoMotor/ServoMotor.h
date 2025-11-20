#pragma once

#include <Arduino.h>
#include <Servo.h>

#include "devices/Motor.h"

class ServoMotor : public Motor {
  private:
    Servo motor;
    uint8_t pin;

  public:
    ServoMotor(uint8_t pin) : pin(pin) {};

    void on() override;

    void off() override;

    void setPosition(int angle) override;
};
