#include "Pir.h"

void Pir::begin() {
    pinMode(this->pin, INPUT);
}

void Pir::sync() {
    this->detected = digitalRead(this->pin) == HIGH;
    this->updateSyncTime(millis());
}

bool Pir::isDetected() {
    return this->detected;
}

void Pir::calibrate() {
    delay(10000);
}

void Pir::updateSyncTime(const long time) {
    this->lastTimeSync = time;
}

long Pir::getLastSyncTime() {
    return this->lastTimeSync;
}
