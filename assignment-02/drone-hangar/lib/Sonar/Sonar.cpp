#include "Sonar.h"

#include "Arduino.h"

void Sonar::setTemperature(const float temperature) {
    this->temperature = temperature;
}

float Sonar::getSoundSpeed() { return 331.5 + 0.6 * this->temperature; }

float Sonar::getDistance() {
    digitalWrite(this->trigPin, LOW);
    delayMicroseconds(3);
    digitalWrite(this->trigPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(this->trigPin, LOW);

    float tUS = pulseIn(this->echoPin, HIGH, this->timeOut);
    if (tUS == 0) {
        return NO_OBJ_DETECTED;
    } else {
        float t = tUS / 1000.0 / 1000.0 / 2;
        float d = t * getSoundSpeed();
        return d;
    }
}