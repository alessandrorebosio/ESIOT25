#pragma once

#include <Arduino.h>

#include "devices/Light.h"
#include "devices/Motor.h"
#include "devices/PresenceSensor.h"
#include "devices/ProximitySensor.h"
#include "devices/Switch.h"
#include "devices/TempSensor.h"

enum State {
    INSIDE,
    TAKEOOF,
    OUTSIDE,
    LANDING,
};

class HWPlatform {
  private:
    Switch *button;
    Light *led1;
    Light *led2;
    Light *led3;
    PresenceSensor *pir;
    Motor *motor;
    ProximitySensor *sonar;
    TempSensor *tempSensor;

    State state;

  public:
    HWPlatform();

    void init();
};
