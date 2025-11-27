#pragma once

#include <Arduino.h>

#include <Button.h>
#include <Lcd.h>
#include <Led.h>
#include <Motor.h>
#include <Pir.h>
#include <Sonar.h>
#include <TMP36.h>

#include "config.h"

class Hardware {
  private:
	Button button;
	Led led1;
	Led led2;
	Led led3;
	Motor motor;
	Pir pir;
	Sonar sonar;
	TMP36 tempSensor;
	Lcd lcd;

  public:
	Hardware();

	~Hardware() = default;
};
