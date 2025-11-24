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

void HWPlatform::printOnLcd(const String text) {
    this->lcd->print(text);
}

void HWPlatform::turnLedOffs() {
    this->led1->off();
    this->led2->off();
    this->led3->off();
}

bool HWPlatform::isDetected() {
    return this->pir->isDetected();
}

bool HWPlatform::isOverTemperature(int temp) {
    return this->tempSensor->getTemperature() > temp;
}

bool HWPlatform::isOverDistance(int distance) {
    return this->sonar->getDistance() > distance;
}

Light *HWPlatform::getL2() {
    return this->led2;
}

Motor *HWPlatform::getMotor() {
    return this->motor;
}

ProximitySensor *HWPlatform::getSonar() {
    return this->sonar;
}
