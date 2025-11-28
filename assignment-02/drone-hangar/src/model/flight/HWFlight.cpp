#include "model/flight/HWFlight.h"

HWFlight::HWFlight(Pir &pir, Sonar &sonar, TMP36 &temp, Lcd &lcd) : pir(pir), sonar(sonar), temp(temp), lcd(lcd) {
}

bool HWFlight::isDetected() {
    return this->pir.isDetected();
}

float HWFlight::distance() {
    this->sonar.setTemperature(this->temp.readTemperature());
    return this->sonar.readDistance();
}

void HWFlight::printOnLcd(String msg) {
    this->lcd.print(msg);
}
