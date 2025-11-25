#pragma once

#include "Device.h"

class PresenceSensor : public Device {
  public:
    explicit PresenceSensor(uint8_t pin) : Device(pin) {
    }

    virtual bool isDetected() = 0;

    virtual void calibrate();

    virtual ~PresenceSensor() = default;
    
};
