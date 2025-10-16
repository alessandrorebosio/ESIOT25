#include <Arduino.h>

#include "logic.h"
#include "utils.h"

/**
 * @file logic.cpp
 * @brief Core game logic for TOS: utilities for button handling, difficulty and
 * LED effects.
 *
 * This file contains timing constants, static variables that keep the state of
 * the LED fade effect and the functions used by the main sketch loop (e.g.
 * press checks, difficulty calculation, LED animation).
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
static int brightness = 0;

/** Amount to add/subtract on each fade step. Can be positive or negative. */
static int fadeAmount = 5;

/**
 * @brief Generates a random sequence of button indices.
 *
 * Creates an array of integers representing the sequence of buttons that 
 * the player must press. Each value corresponds to an index in the BUTTON array.
 * The sequence contains all numbers from 0 to seqLength-1 in random order.
 *
 * @param seq Pointer to GameSequence struct to populate
 * @param seqLength The length of the sequence to generate
 */
void initSequence(GameSequence *seq, int seqLength) {
    seq->length = seqLength;
    resetSequence(seq);
    for (int i = 0; i < seqLength; i++) {
        seq->sequence[i] = i;
    }
}

/**
 * @brief Randomly shuffles the existing sequence in place.
 *
 * Uses the Fisher-Yates shuffle algorithm to randomly rearrange
 * the elements of the current sequence to create a new order
 * without changing its length.
 *
 * @param seq Pointer to GameSequence struct to shuffle
 */
void shuffleSequence(GameSequence *seq) {
    for (int i = seq->length - 1; i > 0; i--) {
        int j = random(0, i + 1);
        int temp = seq->sequence[i];
        seq->sequence[i] = seq->sequence[j];
        seq->sequence[j] = temp;
    }
}

/**
 * @brief Prints the current sequence to Serial monitor
 *
 * Displays the sequence in format "Sequence: 1234" where each number
 * represents a button index + 1 (so 1 = B1, 2 = B2, etc.)
 *
 * @param seq Pointer to GameSequence struct to print
 */
void printSequence(const GameSequence *seq) {
    Serial.print("Sequence: ");
    for (int i = 0; i < seq->length; i++) {
        Serial.print(seq->sequence[i] + 1);
    }
    Serial.println();
}

/**
 * @brief Checks if player's button press matches the expected sequence element
 *
 * Compares the pressed button index with the current step in the sequence.
 * Advances the current step if correct. Does not advance sequence if wrong.
 *
 * @param seq Pointer to GameSequence struct containing current game state
 * @param buttonIndex The index of the button that was pressed (0-based)
 * @return true if button matches current sequence step, false otherwise
 */
bool checkPlayerInput(GameSequence *seq, int buttonIndex) {
    if (seq->currentStep >= seq->length) {
        return false;
    }
    bool correct = (buttonIndex == seq->sequence[seq->currentStep]);
    seq->currentStep++;
    return correct;
}

/**
 * @brief Resets sequence progress without changing the sequence itself
 *
 * Sets currentStep back to 0, allowing the same sequence to be re-attempted
 * or marking the sequence as no longer being displayed.
 *
 * @param seq Pointer to GameSequence struct to reset
 */
void resetSequence(GameSequence *seq) {
    seq->currentStep = 0;
    seq->isShowing = false;
}

/**
 * @brief Maps the analog value read from the input pin to a difficulty level
 * (1..4).
 *
 * The function reads the analog value from the specified pin and uses Arduino's
 * `map` function to convert the range 0..1023 into 1..4.
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
    unsigned long now = millis();
    if (now - lastFadeUpdate < FADE_INTERVAL) return;
    lastFadeUpdate = now;

    brightness += fadeAmount;
    if (brightness <= 0 || brightness >= 255) {
        fadeAmount = -fadeAmount;
        brightness = constrain(brightness, 0, 255);
    }

    analogWrite(pin, brightness);
}

/**
 * @brief Determines if the button at index `index` was pressed (with debounce).
 *
 * The function reads the digital state of the pin corresponding to the index,
 * waits for a short debounce period and checks again. If the button is still
 * pressed it blocks until release and returns true.
 *
 * @param index Index in the `BUTTON` array corresponding to the button to
 * check.
 * @return true if the button was pressed and released, false otherwise.
 */
bool wasPressed(int index) {
    int pin = BUTTON[index];

    if (digitalRead(pin) == HIGH) {
        delay(DEBOUNCE_DELAY);
        if (digitalRead(pin) == HIGH) {
            while (digitalRead(pin) == HIGH)
                ;
            return true;
        }
    }
    return false;
}