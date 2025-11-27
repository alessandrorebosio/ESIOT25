#include "Pir.h"

#define CALIBRATION_TIME 10000

Pir::Pir(const uint8_t pin) : pin(pin) {
	pinMode(this->pin, INPUT);
}

bool Pir::isDetected() {
	return digitalRead(this->pin);
}

void Pir::calibrate() {
	delay(CALIBRATION_TIME);
}
