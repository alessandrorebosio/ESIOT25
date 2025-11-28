#pragma once

#include <Arduino.h>

#include <Button.h>
#include <Lcd.h>
#include <Led.h>
#include <Motor.h>
#include <Pir.h>
#include <Sonar.h>
#include <TMP36.h>

class Hardware final {
  private:
    Button *button;
    Led *led1;
    Led *led2;
    Led *led3;
    Motor *motor;
    Pir *pir;
    Sonar *sonar;
    TMP36 *tempSensor;
    Lcd *lcd;

  public:
    void init();

    Button &getButton();

    Led &getLed1();

    Led &getLed2();

    Led &getLed3();

    TMP36 &getTempSensor();

    ~Hardware();
};
