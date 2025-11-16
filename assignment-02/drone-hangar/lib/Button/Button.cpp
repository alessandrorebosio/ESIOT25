#include "Button.h"

/**
 * @file button.cpp
 * @brief Implementation of button debounce helper
 */

/**
 * @brief Handle debounce for a single button
 * @param button Reference to the Button instance
 * @return true if a press event was detected (stable transition to LOW)
 *
 * Behavior:
 * - Read the raw value from the pin (digitalRead)
 * - If the raw reading changed, update the timestamp
 * - If the reading remains stable for more than DEBOUNCE_TIME, update the
 *   stable state (lastReading) and return true when it becomes LOW
 *
 * Note: the circuit is expected to use INPUT_PULLUP, so LOW means "pressed".
 */
bool isPressed(Button &button) {
    uint8_t reading = digitalRead(button.pin);
    unsigned long currentTime = millis();

    if (reading != button.rawReading) {
        button.rawReading = reading;
        button.lastTime = currentTime;
    }

    if ((currentTime - button.lastTime) > DEBOUNCE_TIME) {
        if (button.rawReading != button.lastReading) {
            button.lastReading = button.rawReading;
            return button.lastReading == LOW;
        }
    }

    return false;
}
