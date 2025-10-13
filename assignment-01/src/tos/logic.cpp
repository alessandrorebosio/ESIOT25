#include <Arduino.h>
#include "logic.h"
#include "utils.h"

/**
 * @file logic.cpp
 * @brief Core game logic for TOS: utilities for button handling, difficulty and LED effects.
 *
 * This file contains timing constants, static variables that keep the state of the
 * LED fade effect and the functions used by the main sketch loop (e.g. press checks,
 * difficulty calculation, LED animation).
 */

/** Debounce delay in milliseconds used to filter button bounce */
const unsigned long DEBOUNCE_DELAY = 30;

/** Interval (ms) between fade value updates for the LED effect */
const unsigned long FADE_INTERVAL = 15;

/**
 * Timestamp (millis) of the last fade update.
 * Static variable visible only within this file.
 */
static unsigned long lastFadeUpdate = 0;

/** Current PWM value for the fade effect (0..255) */
static int fadeValue = 0;

/** Amount to add/subtract on each fade step. Can be positive or negative. */
static int fadeAmount = 7;

/**
 * @brief Generates a random sequence of button indices
 * 
 * Creates an array of random integers representing the sequence
 * of buttons that the player must press. Each value corresponds
 * to an index in the BUTTON array.
 * 
 * @param size The length of the sequence to generate
 * @return Pointer to dynamically allocated array containing the sequence
 */
int *sequence(int size) {
    //TODO
    return NULL;
}

/**
 * @brief Maps the analog value read from the input pin to a difficulty level (1..4).
 *
 * The function reads the analog value from the specified pin and uses Arduino's `map`
 * function to convert the range 0..1023 into 1..4.
 *
 * @param pin Analog pin to read the difficulty knob from.
 * @return Integer between 1 and 4 representing the selected difficulty.
 */
int difficulty(int pin) { return map(analogRead(pin), 0, 1023, 1, 4); }

/**
 * @brief Updates the fade effect on a PWM pin.
 *
 * This function implements an incremental/decremental fade cycle for the
 * PWM value using static variables to keep state across calls. The update
 * only occurs if at least FADE_INTERVAL milliseconds have passed since the
 * last update.
 *
 * @param pin PWM pin (e.g. LED) to write the analog value to.
 */
void ledFade(int pin) {
    unsigned long currentMillis = millis();
    if (currentMillis - lastFadeUpdate >= FADE_INTERVAL)
    {
        lastFadeUpdate = currentMillis;
        fadeValue += fadeAmount;

        if (fadeValue <= 0 || fadeValue >= 255)
            fadeAmount = -fadeAmount;

        analogWrite(pin, fadeValue);
    }
}

/**
 * @brief Determines if the button at index `index` was pressed (with debounce).
 *
 * The function reads the digital state of the pin corresponding to the index,
 * waits for a short debounce period and checks again. If the button is still
 * pressed it blocks until release and returns true.
 *
 * @param index Index in the `BUTTON` array corresponding to the button to check.
 * @return true if the button was pressed and released, false otherwise.
 */
bool wasPressed(int index) {
    int pin = BUTTON[index];

    if (digitalRead(pin) == HIGH) {
        delay(DEBOUNCE_DELAY);
        if (digitalRead(pin) == HIGH) {
            while (digitalRead(pin) == HIGH);
            return true;
        }
    }
    return false;
}