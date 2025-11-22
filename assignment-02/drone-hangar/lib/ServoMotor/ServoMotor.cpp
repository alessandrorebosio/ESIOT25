#include "ServoMotor.h"

ServoMotor::ServoMotor(const uint8_t pin) : Motor(pin) {
}

void ServoMotor::on() {
    this->motor.attach(this->pin);
}

void ServoMotor::off() {
    this->motor.detach();
}

void ServoMotor::setPosition(short angle) {
    if (angle > 180) {
        angle = 180;
    } else if (angle < 0) {
        angle = 0;
    }
    // 750 -> 0, 2250 -> 180
    // 750 + angle*(2250-750)/180
    // updated values: min is 544, max 2400 (see ServoTimer2 doc)
    float coeff = (2400.0 - 544.0) / 180;
    this->motor.write(544 + angle * coeff);
}
