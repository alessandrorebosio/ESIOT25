#include "Sonar.h"

#include "Arduino.h"

#define DELAY1 3
#define DELAY2 5

void Sonar::setTemperature(const float temperature) {
    this->temperature = temperature;
}

float Sonar::getSoundSpeed() { return 331.5 + 0.6 * this->temperature; }

float Sonar::getDistance() {
    digitalWrite(this->trigPin, LOW);
    delayMicroseconds(DELAY1);
    digitalWrite(this->trigPin, HIGH);
    delayMicroseconds(DELAY2);
    digitalWrite(this->trigPin, LOW);

    float tUS = pulseIn(this->echoPin, HIGH, this->timeOut);
    if (tUS == 0) {
        return NO_OBJ_DETECTED;
    } else {
        float t = tUS * 1e-6f / 2.0f;
        float d = t * getSoundSpeed();
        return d;
    }
}

void Sonar::begin() {
    pinMode(this->trigPin, OUTPUT);
    pinMode(this->echoPin, INPUT);
}

int Sonar::equals(int value) {
    float d = this->getDistance();
    if (d == NO_OBJ_DETECTED) {
        return 0;
    }
    return (int)d == value;
}
