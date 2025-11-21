#include <ServoMotor.h>

void ServoMotor::on() {
    motor.attach(this->pin);
}

void ServoMotor::off() {
    motor.detach();
}

void ServoMotor::setPosition(int angle) {
    if (angle > 180) {
        angle = 180;
    } else if (angle < 0) {
        angle = 0;
    }
    // 750 -> 0, 2250 -> 180
    // 750 + angle*(2250-750)/180
    // updated values: min is 544, max 2400 (see ServoTimer2 doc)
    float coeff = (2400.0 - 544.0) / 180;
    motor.write(544 + angle * coeff);
}
