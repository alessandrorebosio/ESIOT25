#include "Led.h"

#define PERIOD 500

/**
 * @file Led.cpp
 * @brief Implementation of LED control functions.
 *
 * The functions use Arduino APIs: `digitalWrite()` and `millis()` for
 * non-blocking timing.
 */

/**
 * @brief Turn the LED on using the configured pin.
 *
 * Drives the stored `pin` to `HIGH`.
 */
void Led::turnOn() { digitalWrite(this->pin, HIGH); }

/**
 * @brief Turn the LED off using the configured pin.
 *
 * Drives the stored `pin` to `LOW`.
 */
void Led::turnOff() { digitalWrite(this->pin, LOW); }

/**
 * @brief Non-blocking blinking implementation.
 *
 * This implementation toggles the LED state every `PERIOD` milliseconds
 * using `millis()` and static state variables. It is non-blocking and
 * suitable for calling frequently from the main loop.
 */
void Led::blinking() {
    static unsigned long lastToggle = 0;
    static bool ledState = false;

    unsigned long now = millis();
    if (now - lastToggle >= PERIOD) {
        lastToggle = now;
        ledState = !ledState;
        ledState ? turnOn() : turnOff();
    }
}
