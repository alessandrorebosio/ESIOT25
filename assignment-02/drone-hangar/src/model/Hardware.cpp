#include "model/Hardware.h"

#include "config.h"

void Hardware::init() {
    button = new Button(BUTTON_PIN, INPUT);
    led1 = new Led(LED1_PIN);
    led2 = new Led(LED2_PIN);
    led3 = new Led(LED3_PIN);
    motor = new Motor(SERVO_PIN);
    pir = new Pir(PIR_PIN);
    sonar = new Sonar(SONAR_TRIG_PIN, SONAR_ECHO_PIN, MAXTIME);
    tempSensor = new TMP36(TEMPERATURE_PIN);
    lcd = new Lcd(LCD_ADDR, LCD_COLS, LCD_ROWS);
}

Button &Hardware::getButton() {
    return *this->button;
}

Led &Hardware::getLed1() {
    return *this->led1;
}

Led &Hardware::getLed2() {
    return *this->led2;
}

Led &Hardware::getLed3() {
    return *this->led3;
}

Pir &Hardware::getPir() {
    return *this->pir;
}

Sonar &Hardware::getSonar() {
    return *this->sonar;
}

TMP36 &Hardware::getTempSensor() {
    return *this->tempSensor;
}

Motor &Hardware::getMotor() {
    return *this->motor;
}

Lcd &Hardware::getLcd(){
    return *this->lcd;
}

Hardware::~Hardware() {
    delete this->button;
    delete this->led1;
    delete this->led2;
    delete this->led3;
    delete this->motor;
    delete this->pir;
    delete this->sonar;
    delete this->tempSensor;
    delete this->lcd;
}
