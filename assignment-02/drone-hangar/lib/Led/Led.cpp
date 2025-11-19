#include "Led.h"

/**
 * @file Led.cpp
 * @brief Implementation of LED control functions.
 *
 * The functions use Arduino APIs: `digitalWrite()` and `millis()` for
 * non-blocking timing.
 */

#define PERIOD 500

static unsigned long lastToggle = 0;
static bool ledState = false;

/**
 * @brief Construct a Led instance bound to a digital pin.
 *
 * @param pin Digital input pin number where the led is connected.
 */
Led::Led(const uint8_t pin) { this->pin = pin; }

/**
 * @brief Configure the LED pin as output and prepare timing state.
 *
 * Sets the configured pin to `OUTPUT` and ensures any timers or state
 * used by blinking are ready. Call once during the application setup
 * phase before using `turnOn()`, `turnOff()` or `blinking()`.
 */
void Led::begin() { pinMode(this->pin, OUTPUT); }

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
void Led::blinking()
{
    unsigned long now = millis();
    if (now - lastToggle >= PERIOD)
    {
        lastToggle = now;
        ledState = !ledState;
        ledState ? turnOn() : turnOff();
    }
}
