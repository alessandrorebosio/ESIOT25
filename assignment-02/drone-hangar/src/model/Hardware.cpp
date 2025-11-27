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

TMP36 &Hardware::getTempSensor() {
    return *this->tempSensor;
}

Hardware::~Hardware() {
    delete button;
    delete led1;
    delete led2;
    delete led3;
    delete motor;
    delete pir;
    delete sonar;
    delete tempSensor;
    delete lcd;
}
