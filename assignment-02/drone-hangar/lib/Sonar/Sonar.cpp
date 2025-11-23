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
    delayMicroseconds(DELAY1);
    trig.write(HIGH);
    delayMicroseconds(DELAY2);
    trig.write(LOW);

    float tUS = pulseIn(this->echo.getPin(), HIGH, this->timeOut);
    if (tUS == 0) {
        return NO_OBJ_DETECTED;
    } else {
        float t = tUS * 1e-6f / 2.0f;
        float d = t * getSoundSpeed();
        return d;
    }
}
