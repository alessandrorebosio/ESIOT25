#pragma once

#include <Motor.h>

class HWGate final {
  private:
    Motor &motor;

  public:
    explicit HWGate(Motor &motor);

    void motorOn();

    void motorOff();

    void setPosition(short angle);

    ~HWGate() = default;
};
