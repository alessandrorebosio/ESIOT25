#pragma once

#include <Arduino.h>

class Switch {
  public:
    virtual void begin() = 0;

    virtual bool isPressed() = 0;
};
