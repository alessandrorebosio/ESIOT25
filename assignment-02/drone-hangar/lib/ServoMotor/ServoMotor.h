#pragma once

#include <Servo.h>

#include "devices/Motor.h"

class ServoMotor : public Motor {
  private:
    Servo motor;

  public:
    explicit ServoMotor(uint8_t pin);

    void on() override;

    void off() override;

    void setPosition(short angle) override;
};
