#include <Arduino.h>

#include "logic.h"
#include "utils.h"

#define START_VALUE 0
#define INCREMENT 1

/**
 * @file logic.cpp
 * @brief Core game logic for TOS: utilities for button handling, difficulty and
 * LED effects.
 *
 * This file contains timing constants, static variables that keep the state of
 * the LED fade effect and the functions used by the main sketch loop (e.g.
 * press checks, difficulty calculation, LED animation).
 */

/**
 * Debounce delay in milliseconds used to filter button bounce
 */
const unsigned long DEBOUNCE_DELAY = 30;

/**
 * Interval (ms) between fade value updates for the LED effect
 */
const unsigned long FADE_INTERVAL = 15;

/**
 * Timestamp (millis) of the last fade update.
 * Static variable visible only within this file.
 */
static unsigned long lastFadeUpdate = 0;

/**
 * Current PWM value for the fade effect (0..255)
 */
static int brightness = 0;

/**
 * Amount to add/subtract on each fade step. Can be positive or negative.
 */
static int fadeAmount = 5;

/**
 * @brief File-local GameSequence instance representing the current game
 * sequence/state.
 *
 * This static variable holds the active sequence of game steps, events and/or
 * state used by the application. Declared at file scope with internal linkage,
 * it is only visible within this translation unit and has program-lifetime
 * duration (default-constructed before main).
 *
 * Access and modify this object through the GameSequence public API. If the
 * program uses multiple threads, synchronize access to this variable to avoid
 * data races and undefined behavior. Initialize or reset it explicitly where
 * appropriate rather than relying on implicit assumptions about its initial
 * contents.
 */
static Game game;

/**
 * @brief Initialize the global game sequence and related state.
 *
 * This function releases any previously allocated sequence buffer,
 * allocates a new integer array of size LEN, sets game.length to LEN,
 * and populates the array with ascending values 0 .. LEN-1.
 *
 * @pre The global 'game' object and the compile-time constant LEN must be
 * defined. LEN is expected to be non-negative; behavior is undefined for
 * negative LEN.
 *
 * @post game.sequence points to a newly allocated int array of length
 * game.length (== LEN). Any previously allocated buffer is deleted and the
 * pointer cleared before allocation.
 *
 * @throws std::bad_alloc If memory allocation for the new sequence fails.
 */
void gameInit(int len) {
    if (game.sequence) {
        delete[] game.sequence;
        game.sequence = nullptr;
    }

    game.sequence = new int[len];
    game.length = len;
    game.isShowing = false;

    for (int i = 0; i < game.length; ++i) {
        game.sequence[i] = i;
    }
}

/**
 * @brief Return the current score value.
 *
 * @return Current score.
 */
int getScore(void) { return game.score; }

/**
 * @brief Increment the score by one.
 */
void increaseScore(void) { game.score += INCREMENT; }

/**
 * @brief Randomly shuffles the existing sequence in place.
 *
 * Uses the Fisher-Yates shuffle algorithm to randomly rearrange
 * the elements of the current sequence to create a new order
 * without changing its length.
 */
void shuffleSequence(void) {
    for (int i = game.length - 1; i > 0; --i) {
        int j = random(0, i + 1);
        int temp = game.sequence[i];
        game.sequence[i] = game.sequence[j];
        game.sequence[j] = temp;
    }

    game.step = START_VALUE;
    game.isShowing = true;
}

/**
 * @brief Determine whether a new sequence should be started.
 *
 * Evaluates the current internal state and decides if the caller must
 * begin a new sequence (for example because the current sequence has
 * completed, a delimiter was encountered, or timing/size thresholds
 * have been exceeded).
 *
 * @return true if a new sequence is required; false otherwise.
 */
bool needsNewSequence(void) { 
    return  !game.isShowing; 
}

/**
 * @brief Retrieve the integer sequence used by the logic module.
 *
 * This function returns a pointer to the first element of a contiguous sequence
 * of int values produced/managed by the logic layer. The number of elements in
 * the sequence is not encoded in the pointer itself; callers must obtain the
 * sequence length via the corresponding API function (if available) or by
 * other means defined by the module.
 *
 * @return Pointer to the first element of the int sequence, or nullptr on
 * error.
 */
int *getSequence(void) { return game.sequence; }

/**
 * @brief Checks if player's button press matches the expected sequence element
 *
 * Compares the pressed button index with the current step in the sequence.
 * Advances the current step if correct. Does not advance sequence if wrong.
 *
 * @param buttonIndex The index of the button that was pressed (0-based)
 * @return true if button matches current sequence step, false otherwise
 */
bool checkButton(int buttonIndex) {
    return (game.step < game.length && game.sequence[game.step] == buttonIndex) 
        ? (game.step++, true) 
        : false;
}

/**
 * @brief Check if the current sequence has been completed.
 *
 * Evaluates whether the player has successfully completed the current
 * sequence based on internal game state.
 *
 */
bool isSequenceCompleted(void) {
    return game.step >= game.length;
}

/**
 * @brief Reset the current game's score.
 *
 * Sets the global game's score to zero, effectively restarting the
 * player's score while leaving other game state fields unchanged.
 */
void reset(void) {
    if(!isSequenceCompleted()) {
        game.score = START_VALUE;
    }
    game.step = START_VALUE;
    game.isShowing = false;
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
 * @brief Check if a digital input pin is being pressed, with a simple debounce
 * delay.
 *
 * Reads the specified digital pin using digitalRead(). If the pin reads HIGH,
 * the function performs a blocking delay of DEBOUNCE_DELAY milliseconds and
 * returns true. If the pin reads LOW, the function returns false immediately.
 *
 * @param pin The Arduino digital pin number to read.
 * @return true if the pin was read HIGH (press detected); false otherwise.
 */
bool wasPressed(int pin) {
    return digitalRead(pin) ? (delay(DEBOUNCE_DELAY), true) : false;
}