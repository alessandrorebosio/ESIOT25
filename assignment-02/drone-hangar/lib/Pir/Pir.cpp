#include "Pir.h"

#define CALIBRATION_TIME 10000

Pir::Pir(const uint8_t pin) : PresenceSensor(pin) {
    Device::begin(INPUT);
}

bool Pir::isDetected() {
    return Device::read();
}

void Pir::calibrate() {
    delay(CALIBRATION_TIME);
}
