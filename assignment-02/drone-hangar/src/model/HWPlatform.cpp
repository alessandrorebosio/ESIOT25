#include "model/HWPlatform.h"

#include <Button.h>
#include <Led.h>
#include <Pir.h>
#include <ServoMotor.h>
#include <Sonar.h>
#include <TempSensorTMP36.h>

#include "config.h"

HWPlatform::HWPlatform(MsgService *msg) : msg(msg) {
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

MsgService *HWPlatform::serial() {
    return this->msg;
}

bool HWPlatform::isPressed() {
    return this->button->isPressed();
}

void HWPlatform::turnOnL1() {
    this->led1->on();
}

void HWPlatform::turnOnL3() {
    this->led3->on();
}

void HWPlatform::turnOffL3() {
    this->led3->off();
}

bool HWPlatform::isOverTemperature1() {
    return this->isOverTemperature(TEMP1);
}

bool HWPlatform::isOverTemperature2() {
    return this->isOverTemperature(TEMP2);
}

bool HWPlatform::isOverTemperature(unsigned short temperature) {
    return this->tempSensor->getTemperature() >= temperature;
}
