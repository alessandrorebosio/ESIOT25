#include "Button.h"

#define DEBOUNCE_TIME 50

Button::Button(const uint8_t pin) : Switch(pin) {
    Device::begin(INPUT);
}

bool Button::isPressed() {
    return Device::read();
}
