#pragma once

#include <Arduino.h>

class Motor {
  public:
    virtual void on() = 0;

    virtual void off() = 0;

    virtual void setPosition(int angle) = 0;
};
