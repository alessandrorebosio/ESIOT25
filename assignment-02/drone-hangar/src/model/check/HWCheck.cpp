#include "model/check/HWCheck.h"

HWCheck::HWCheck(Sonar &sonar, TMP36 &temp) : sonar(sonar), temp(temp) {
}

float HWCheck::distance(void) {
    this->sonar.setTemperature(this->temp.readTemperature());
    return this->sonar.readDistance();
}
