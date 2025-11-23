#pragma once

#include <Arduino.h>

#include "devices/Light.h"
#include "devices/Motor.h"
#include "devices/PresenceSensor.h"
#include "devices/ProximitySensor.h"
#include "devices/Switch.h"
#include "devices/TempSensor.h"
#include <Lcd.h>

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

  public:
    HWPlatform();

    void init();

    bool isPressed();

    void printOnLcd(String text);

    Motor *getMotor();
    ProximitySensor *getSonar();
};
