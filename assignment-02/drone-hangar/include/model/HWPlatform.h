#pragma once

#include <Arduino.h>

#include "devices/Light.h"
#include "devices/Motor.h"
#include "devices/PresenceSensor.h"
#include "devices/ProximitySensor.h"
#include "devices/Switch.h"
#include "devices/TempSensor.h"
#include <Lcd.h>

#include "common/State.h"

class HWPlatform {
  private:
    Switch *button;
    Lcd *lcd;
    Light *led1;
    Light *led2;
    Light *led3;
    PresenceSensor *pir;
    Motor *motor;
    ProximitySensor *sonar;
    TempSensor *tempSensor;

    State<HWPlatform> *state;

  public:
    HWPlatform();

    void init();

    float getTemperature();

    float getDistance();

    bool isDetected();

    bool isButtonPressed();

    void changeState(State<HWPlatform> *newState);

    void ledOffs();

    void printOnLcd(String text);

    Light *getLed(uint8_t index);
};
