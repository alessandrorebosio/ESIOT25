#pragma once

#include "../../include/devices/ProximitySensor.h"

#define NO_OBJ_DETECTED -1

class Sonar : public ProximitySensor {
  private:
    uint8_t trigPin, echoPin;
    float temperature;
    long timeOut;

    float getSoundSpeed();

  public:
    Sonar(uint8_t trigPin, uint8_t echoPin, long maxTime)
        : trigPin(trigPin), echoPin(echoPin), timeOut(maxTime) {
        this->temperature = 20;
        this->begin();
    }

    void begin() override;

    void setTemperature(const float temperature);

    float getDistance() override;

    int equals(int value) override;
};
