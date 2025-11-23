#include "Button.h"

#define DEBOUNCE_TIME 50

Button::Button(const uint8_t pin) : Switch(pin) {
    Device::begin(INPUT);
}

bool Button::isPressed() {
    unsigned long currentTime = millis();
    rawReading = digitalRead(pin);

    if (rawReading != lastReading) {
        lastTime = currentTime;
    }

    if ((currentTime - lastTime) > DEBOUNCE_TIME && rawReading == HIGH) {
        lastReading = rawReading;
        return true;
    }

    lastReading = rawReading;
    return false;
}
