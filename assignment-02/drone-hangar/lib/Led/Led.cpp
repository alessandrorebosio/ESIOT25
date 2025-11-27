#include "Led.h"

Led::Led(const uint8_t pin) : pin(pin) {
	pinMode(this->pin, OUTPUT);
}

void Led::on() {
	digitalWrite(this->pin, HIGH);
}

void Led::off() {
	digitalWrite(this->pin, LOW);
}
