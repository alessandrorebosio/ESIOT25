#include "Led.h"

#define PERIOD 500

/**
 * @file Led.cpp
 * @brief Implementation of LED control functions.
 *
 * The functions use Arduino APIs: `digitalWrite()` and `delay()`.
 */

/**
 * @brief Turn the LED on at the given pin.
 * @param pin Digital pin number where the LED is connected.
 */
void turnOn(const uint8_t pin) { digitalWrite(pin, HIGH); }

/**
 * @brief Turn the LED off at the given pin.
 * @param pin Digital pin number where the LED is connected.
 */
void turnOff(const uint8_t pin) { digitalWrite(pin, LOW); }

/**
 * @brief Blink the LED once using a fixed period.
 * @param pin Digital pin of the LED.
 *
 * Sequence: ON -> delay(PERIOD) -> OFF -> delay(PERIOD).
 * This is a blocking function (uses `delay()`), so it is not suitable
 * for non-blocking timing or time-critical tasks.
 */
void blinking(const uint8_t pin) {
    static unsigned long lastToggle = 0;
    static bool ledState = false;

    unsigned long now = millis();
    if (now - lastToggle >= PERIOD) {
        lastToggle = now;
        ledState = !ledState;
        ledState ? turnOn(pin) : turnOff(pin);
    }
}
