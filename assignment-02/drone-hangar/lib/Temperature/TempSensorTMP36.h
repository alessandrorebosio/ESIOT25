#pragma once

#include <Arduino.h>

#include "Device/TempSensor.h"

class TempSensorTMP36 : public TempSensor {
  private:
    uint8_t pin;

  public:
    TempSensorTMP36(const uint8_t pin) : pin(pin) { this->begin(); }

    void begin();

    float getTemperature() override;
};
