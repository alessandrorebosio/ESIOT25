#include "Led.h"

Led::Led(const uint8_t pin) : Light(pin) {
    Device::begin(OUTPUT);
}

void Led::on() {
    this->write(HIGH);
}

void Led::off() {
    this->write(LOW);
}
