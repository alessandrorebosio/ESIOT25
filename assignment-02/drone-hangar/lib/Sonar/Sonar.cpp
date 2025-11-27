#include "Sonar.h"

#define NO_OBJ_DETECTED -1.0f

#define DELAY1 2
#define DELAY2 10

Sonar::Sonar(uint8_t trigPin, uint8_t echoPin, unsigned long maxTime)
    : trigPin(trigPin), echoPin(echoPin), temperature(20.0f), timeOut(maxTime) {
    pinMode(this->trigPin, OUTPUT);
    pinMode(this->echoPin, INPUT);

    digitalWrite(this->trigPin, LOW);
}

void Sonar::setTemperature(const float temperature) {
    this->temperature = temperature;
}

float Sonar::getSoundSpeed() {
    return 331.5 + 0.6 * this->temperature;
}

float Sonar::readDistance() {
    digitalWrite(this->trigPin, LOW);
    delayMicroseconds(DELAY1);
    digitalWrite(this->trigPin, HIGH);
    delayMicroseconds(DELAY2);
    digitalWrite(this->trigPin, LOW);

    unsigned long tUS = pulseIn(this->echoPin, HIGH, this->timeOut);
    if (tUS == 0UL) {
        return NO_OBJ_DETECTED;
    }

    // Convert microseconds to seconds, divide by 2 (round-trip), multiply by
    // speed (m/s) and convert to cm
    return tUS * 1e-6f * 0.5f * this->getSoundSpeed() * 100.0f;
}
