#pragma once

#include "devices/Device.h"
#include "devices/ProximitySensor.h"

class Sonar : public ProximitySensor {
  private:
    Device trig, echo;
    float temperature;
    long timeOut;

    float getSoundSpeed();

  public:
    Sonar(uint8_t trigPin, uint8_t echoPin, long maxTime);

    void begin() override;

    void setTemperature(const float temperature) override;

    float getDistance() override;
};
