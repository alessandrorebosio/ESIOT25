#include "Button.h"

Button::Button(const uint8_t pin, const uint8_t mode) : pin(pin) {
    pinMode(this->pin, mode);
}

bool Button::isPressed() {
    return digitalRead(pin);
}
