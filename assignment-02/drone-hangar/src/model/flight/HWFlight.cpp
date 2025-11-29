#include "model/flight/HWFlight.h"

HWFlight::HWFlight(Pir &pir, Sonar &sonar, TMP36 &temp) : pir(pir), sonar(sonar), temp(temp) {
}

bool HWFlight::isDetected(void) {
    return this->pir.isDetected();
}

float HWFlight::distance(void) {
    this->sonar.setTemperature(this->temp.readTemperature());
    return this->sonar.readDistance();
}
