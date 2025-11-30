#include "model/takeoff/HWTakeOff.h"

HWTakeOff::HWTakeOff(Sonar &sonar, TMP36 &temp) : sonar(sonar), temp(temp) {
}

float HWTakeOff::distance(void) {
    this->sonar.setTemperature(this->temp.readTemperature());
    return this->sonar.readDistance();
}
