#pragma once

#include <Arduino.h>
#include <Servo.h>

#include "Device/Motor.h"

class MyServo : public Motor {
  private:
    Servo motor;
    uint8_t pin;

  public:
    MyServo(uint8_t pin) : pin(pin) {};

    void on() override;

    void off() override;

    void setPosition(int angle) override;
};
