#pragma once

#include <Arduino.h>

class Sonar final {
  private:
    uint8_t trigPin, echoPin;
    float temperature;
    long timeOut;

    float getSoundSpeed();

  public:
    Sonar(uint8_t trigPin, uint8_t echoPin, unsigned long maxTime);

    void setTemperature(float temperature);

    float readDistance();
};
