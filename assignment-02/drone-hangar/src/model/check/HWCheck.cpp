#include "model/check/HWCheck.h"

HWCheck::HWCheck(Sonar &sonar, TMP36 &temp, Lcd &lcd) : sonar(sonar), temp(temp), lcd(lcd) {
}

float HWCheck::distance() {
    this->sonar.setTemperature(this->temp.readTemperature());
    return this->sonar.readDistance();
}

void HWCheck::printOnLcd(String msg) {
    this->lcd.print(msg);
}
