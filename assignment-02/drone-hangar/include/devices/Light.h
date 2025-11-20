#pragma once

#include <Arduino.h>

class Light {
  public:
    virtual void begin() = 0;

    virtual void on() = 0;

    virtual void off() = 0;
};
