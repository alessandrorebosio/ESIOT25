#include "model/landing/HWLanding.h"

HWLanding::HWLanding(Sonar &sonar, TMP36 &temp) : sonar(sonar), temp(temp) {
}

float HWLanding::distance(void) {
    this->sonar.setTemperature(this->temp.readTemperature());
    return this->sonar.readDistance();
}
