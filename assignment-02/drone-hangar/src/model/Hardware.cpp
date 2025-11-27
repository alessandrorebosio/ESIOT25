#include "model/Hardware.h"
#include "config.h"

Hardware::Hardware()
	: button(BUTTON_PIN, INPUT), led1(LED1_PIN), led2(LED2_PIN), led3(LED3_PIN),
	  motor(SERVO_PIN), pir(PIR_PIN),
	  sonar(SONAR_TRIG_PIN, SONAR_ECHO_PIN, MAXTIME),
	  tempSensor(TEMPERATURE_PIN), lcd(LCD_ADDR, LCD_COLS, LCD_ROWS) {
}

Led &Hardware::getLed3() {
	return this->led3;
}
