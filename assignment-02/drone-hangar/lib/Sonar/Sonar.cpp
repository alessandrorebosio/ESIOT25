#include "Sonar.h"

#define NO_OBJ_DETECTED -1

#define DELAY1 3
#define DELAY2 5

Sonar::Sonar(uint8_t trigPin, uint8_t echoPin, long maxTime)
    : trig(trigPin), echo(echoPin), temperature(20.0f), timeOut(maxTime) {
    this->begin();
}

void Sonar::begin() {
    trig.begin(OUTPUT);
    echo.begin(INPUT);
}

void Sonar::setTemperature(const float temperature) {
    this->temperature = temperature;
}

float Sonar::getSoundSpeed() {
    return 331.5 + 0.6 * this->temperature;
}

float Sonar::getDistance() {
    trig.write(LOW);
    delayMicroseconds(2);
    trig.write(HIGH);
    delayMicroseconds(10);
    trig.write(LOW);

    unsigned long tUS = pulseIn(this->echo.getPin(), HIGH, this->timeOut);
    if (tUS == 0UL) {
        return NO_OBJ_DETECTED;
    }

    // Convert microseconds to seconds, divide by 2 (round-trip), multiply by speed (m/s) and convert to cm
    const float secondsPerMicro = 1e-6f;
    float distanceCm = tUS * secondsPerMicro * 0.5f * this->getSoundSpeed() * 100.0f;
    return distanceCm;
}
