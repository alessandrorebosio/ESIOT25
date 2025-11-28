#include "model/gate/HWGate.h"

HWGate::HWGate(Motor &motor) : motor(motor) {
}

void HWGate::motorOn() {
    this->motor.on();
}

void HWGate::motorOff() {
    this->motor.off();
}

void HWGate::setPosition(short angle) {
    this->motor.setPosition(angle);
}
