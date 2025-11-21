#include "Button.h"

#define DEBOUNCE_TIME 50

void Button::begin() {
    pinMode(this->pin, INPUT);
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
