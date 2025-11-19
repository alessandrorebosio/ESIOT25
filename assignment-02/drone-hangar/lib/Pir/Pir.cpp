#include "Pir.h"

void Pir::begin() { pinMode(this->pin, INPUT); }

void Pir::sync() {
    detected = digitalRead(pin) == HIGH;
    updateSyncTime(millis());
}

bool Pir::isDetected() { return detected; }

void Pir::calibrate() { delay(10000); }

void Pir::updateSyncTime(const long time) { lastTimeSync = time; }

long Pir::getLastSyncTime() { return lastTimeSync; }
