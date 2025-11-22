#include "model/HWPlatform.h"

#include <Button.h>
#include <Led.h>
#include <Pir.h>
#include <ServoMotor.h>
#include <Sonar.h>
#include <TempSensorTMP36.h>

#include "config.h"

HWPlatform::HWPlatform() {
    this->init();
}

void HWPlatform::init() {
    this->button = new Button(BUTTON_PIN);
    this->lcd = new Lcd(LCD_ADDR, LCD_COLS, LCD_ROWS);
    this->led1 = new Led(LED1_PIN);
    this->led2 = new Led(LED2_PIN);
    this->led3 = new Led(LED3_PIN);
    this->pir = new Pir(PIR_PIN);
    this->motor = new ServoMotor(SERVO_PIN);
    this->sonar = new Sonar(SONAR_TRIG_PIN, SONAR_ECHO_PIN, MAXTIME);
    this->tempSensor = new TempSensorTMP36(TEMPERATURE_PIN);
}

bool HWPlatform::isPressed() {
    return this->button->isPressed();
}
