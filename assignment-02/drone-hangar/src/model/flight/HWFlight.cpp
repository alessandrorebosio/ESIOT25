#include "model/flight/HWFlight.h"

HWFlight::HWFlight(Pir &pir, Sonar &sonar, TMP36 &temp) : pir(pir), sonar(sonar), temp(temp) {
}

bool HWFlight::isDetected() {
    return this->pir.isDetected();
}

float HWFlight::distance() {
    this->sonar.setTemperature(this->temp.readTemperature());
    return this->sonar.readDistance();
}
