#pragma once

#include "devices/PresenceSensor.h"

class Pir : public PresenceSensor {
  public:
    explicit Pir(const uint8_t pin);

    bool isDetected() override;

    void calibrate() override;
};
