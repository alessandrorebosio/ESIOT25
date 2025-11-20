#pragma once

#include <Arduino.h>

class PresenceSensor {
  public:
    virtual bool isDetected() = 0;
};
