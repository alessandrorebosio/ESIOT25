#include "model/check/HWCheck.h"

HWCheck::HWCheck(Sonar &sonar, TMP36 &temp) : sonar(sonar), temp(temp) {
}

float HWCheck::distance() {
    this->sonar.setTemperature(this->temp.readTemperature());
    return this->sonar.readDistance();
}
