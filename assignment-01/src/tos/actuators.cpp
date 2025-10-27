#include <Arduino.h>

#include "actuators.h"
#include "config.h"

/**
 * @file actuators.cpp
 * @brief Implementation of input and actuator helpers for ToS.
 *
 * This file implements debounced button reading, potentiometer mapping and
 * simple LED utilities such as fading and turning off all LEDs.
 */

/** Timestamp of last fade update (internal state). */
static unsigned long lastFadeUpdate = 0;

/** Current brightness used by ledFade(). */
static int brightness = FADE_INITIAL_BRIGHTNESS;

/** Fade step applied to brightness on each fade update. */
static int fadeAmount = FADE_INITIAL_AMOUNT;

/**
 * @brief Initialize all input and actuator pins.
 *
 * Configures the sequence button pins and the corresponding LED pins.
 * Also configures the potentiometer analog pin. The exact pin mode
 * (INPUT vs INPUT_PULLUP) must match the physical wiring: this code
 * sets button pins to INPUT and assumes external pull-ups or hardware
 * wiring that provides a stable HIGH idle state.
 *
 * @note The status LED identifier used in this file is `LSLED` (legacy).
 * The project-wide name defined in `config.h` is `LSLED_PIN`. Ensure the
 * two identifiers match in the code base; otherwise update references.
 */
void actuatorsInit() {
    for (int i = 0; i < SEQ_LEN; i++) {
        pinMode(BUTTONS[i], INPUT);
        pinMode(LEDS[i], OUTPUT);
    }
    pinMode(POTENTIOMETER_PIN, INPUT);
    pinMode(LSLED, OUTPUT);
}

/**
 * @brief Check for button press with debouncing.
 *
 * Implements a simple stateful debouncing algorithm. The function keeps
 * per-pin state in static arrays and returns true only when a stable
 * falling edge (HIGH -> LOW) is detected for the given pin.
 *
 * @param pin Digital pin number to check.
 * @return true if a valid press is detected, false otherwise.
 *
 * @note Assumes active-LOW button wiring (pressed == LOW).
 * @note Returns false if the provided pin index is out of range.
 */
bool wasPressed(const uint8_t pin) {
    static int lastButtonState[NUM_PINS] = {HIGH};
    static int buttonState[NUM_PINS] = {HIGH};
    static unsigned long lastDebounceTime[NUM_PINS] = {0};

    int reading = digitalRead(pin);
    unsigned long now = millis();

    if (reading != lastButtonState[pin]) {
        lastDebounceTime[pin] = now;
    }

    if ((now - lastDebounceTime[pin]) > DEBOUNCE_DELAY) {
        if (reading != buttonState[pin]) {
            buttonState[pin] = reading;
            if (buttonState[pin] == LOW) {
                lastButtonState[pin] = reading;
                return true;
            }
        }
    } 

    lastButtonState[pin] = reading;
    return false;
}

/**
 * @brief Map the potentiometer analog reading into the game difficulty range.
 *
 * Reads the ADC value from `pin`, then maps it into the integer range
 * [1..LIMIT] where `LIMIT` is the number of difficulty levels.
 *
 * @param pin Analog pin to read (e.g., POTENTIOMETER_PIN).
 * @return Mapped difficulty value in 1..LIMIT.
 */
uint8_t mapPotentiometer(const uint8_t pin) {
    return (uint8_t)map(analogRead(pin), 0, ANALOG_MAX_VALUE, ONE, LIMIT);
}

/**
 * @brief Perform a non-blocking fade animation on the specified PWM pin.
 *
 * This function updates the brightness on `pin` only when the internal
 * timer indicates that FADE_INTERVAL milliseconds have elapsed. Call it
 * frequently from the main loop.
 *
 * @param pin PWM-capable digital pin.
 */
void ledFade(int pin) {
    unsigned long now = millis();
    if (now - lastFadeUpdate < FADE_INTERVAL)
        return;
    lastFadeUpdate = now;

    brightness += fadeAmount;
    if (brightness <= 0 || brightness >= 255) {
        fadeAmount = -fadeAmount;
        brightness = constrain(brightness, 0, 255);
    }

    analogWrite(pin, brightness);
}

/**
 * @brief Turn off all game LEDs (sequence LEDs and status LED).
 *
 * Sets each LED in the sequence to LOW and also writes LOW to the
 * status LED pin.
 */
void turnOffAllLEDs() {
    for (int i = 0; i < SEQ_LEN; i++) {
        digitalWrite(LEDS[i], LOW);
    }
    digitalWrite(LSLED, LOW);
}