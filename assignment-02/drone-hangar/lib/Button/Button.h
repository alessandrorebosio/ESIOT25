#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

/**
 * @file button.h
 * @brief Button debounce utilities and Button state representation
 *
 * This header defines the debounce timeout, the Button struct that keeps
 * per-button state, and the prototype for the isPressed helper that
 * implements a software debounce.
 */

/** @brief Debounce time in milliseconds */
#define DEBOUNCE_TIME 50

/**
 * @struct Button
 * @brief Represents the runtime state of a physical button
 *
 * Fields:
 * - lastTime: last timestamp (millis) when the raw reading changed
 * - lastReading: last stable reading (HIGH/LOW)
 * - rawReading: most recent raw reading from the pin
 * - pin: pin number where the button is connected
 */
struct Button {
    unsigned long lastTime = 0;
    uint8_t lastReading = HIGH;
    uint8_t rawReading = HIGH;
    uint8_t pin;

    Button(uint8_t p) : pin(p) {}
    Button() : Button(0) {}
};

/**
 * @brief Check if a button was pressed (handles debounce)
 * @param button Reference to the Button instance
 * @return true when a stable transition to LOW is detected (pressed)
 *
 * The function updates the raw reading and uses a simple software debounce:
 * when the raw reading stays stable for more than DEBOUNCE_TIME, the stable
 * state (lastReading) is updated. With INPUT_PULLUP wiring, LOW means pressed.
 */
bool isPressed(Button &button);

#endif