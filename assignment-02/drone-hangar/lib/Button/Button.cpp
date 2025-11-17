#include "Button.h"

/**
 * Debounce interval (milliseconds) used to filter mechanical bounce.
 */
#define DEBOUNCE_TIME 50

/**
 * @brief Check whether the button was pressed (debounced).
 *
 * This method implements a non-blocking debounce algorithm:
 * - Read the raw pin state.
 * - If the raw state changed, reset the debounce timer.
 * - When the raw state remains stable longer than `DEBOUNCE_TIME`,
 *   consider it a valid change and report a press event when the
 *   stable state becomes `LOW` (assuming active-low wiring).
 *
 * @return true if a debounced press edge was detected, false otherwise
 */
bool Button::isPressed() {
    int reading = digitalRead(this->pin);
    unsigned long currentTime = millis();

    if (reading != this->rawReading) {
        this->rawReading = reading;
        this->lastTime = currentTime;
    }

    if ((currentTime - this->lastTime) > DEBOUNCE_TIME) {
        if (this->rawReading != this->lastReading) {
            this->lastReading = this->rawReading;
            return this->lastReading == LOW;
        }
    }

    return false;
}

/**
 * @brief Defaulted destructor.
 */
Button::~Button() = default;
