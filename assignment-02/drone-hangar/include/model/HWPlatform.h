#pragma once

#include <Arduino.h>

#include "core/MsgService.h"

#include "config.h"

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

    MsgService *msg;

  public:
    HWPlatform(MsgService *msg);

    MsgService *serial();

    void init();

    bool isPressed();

    void turnOnL1();

    void turnOnL2();

    void turnOffL2();

    void turnOnL3();

    void turnOffL3();

    inline long expired(unsigned long time, unsigned timeout) {
        return millis() - time >= timeout;
    }

    inline long expiredT1(unsigned long time) {
        return expired(time, T1);
    }

    inline long expiredT2(unsigned long time) {
        return expired(time, T2);
    }

    bool isOverTemperature1();

    bool isOverTemperature2();

    bool isOverTemperature(unsigned short temperature);
};
