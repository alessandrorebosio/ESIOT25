#pragma once

#include "devices/TempSensor.h"

class TempSensorTMP36 final : public TempSensor {
  public:
    explicit TempSensorTMP36(uint8_t pin);

    float getTemperature() override;
};
