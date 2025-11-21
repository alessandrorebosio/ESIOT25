#include "Led.h"

void Led::begin() {
    pinMode(this->pin, OUTPUT);
}

void Led::on() {
    digitalWrite(this->pin, HIGH);
}

void Led::off() {
    digitalWrite(this->pin, LOW);
}
