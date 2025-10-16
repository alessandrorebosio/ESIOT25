#ifndef LOGIC_H
#define LOGIC_H

/**
 * @file logic.h
 * @brief Header file for game logic management
 *
 * This file contains declarations for sequence generation,
 * difficulty management, and LED/button control.
 */

/**
 * @brief Game sequence data structure
 *
 * Contains all data related to the current game sequence,
 * including the sequence values, current progress, and
 * display state.
 */
typedef struct {
    /**
     * Array storing the sequence of button indices
     */
    int *sequence;
    /**
     * Current length of the active sequence
     */
    int length;
    /**
     * Current sequence index
     */
    int step;
    /**
     * Current player score
     */
    int score;
} Game;

/**
 * @brief Initialize the game state and sequence.
 *
 * Allocates memory for the game sequence based on the provided length
 * and initializes all relevant fields in the Game struct to their
 * starting values.
 *
 * @param len The desired length of the game sequence.
 */
void gameInit(int len);

/**
 * @brief Get the current score value.
 *
 * @return The current score as an integer.
 */
int getScore(void);

/**
 * @brief Increase the score by one.
 *
 * This increments the internal score counter. If callers require
 * atomic updates in a concurrent environment, they must provide the
 * necessary synchronization.
 */
void increase(void);

/**
 * @brief Shuffles the existing sequence
 *
 * Randomly rearranges the elements of the current sequence
 * to create a new order without changing its length.
 *
 * @param seq Pointer to GameSequence struct to shuffle
 */
void shuffleSequence();

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
int *getSequence(void);

/**
 * @brief Check a player's button input against the game's expected input.
 *
 * Compares the supplied buttonIndex (the index of the button pressed by the
 * player) with the currently expected input according to the game's logic.
 * If the input is correct, the function advances or updates the internal game
 * progress/state accordingly; if incorrect, it updates state to reflect the
 * failure condition (for example decrementing lives, resetting progress, or
 * setting an error flag).
 *
 * @param buttonIndex Index of the button pressed by the player (zero-based).
 *                    Must refer to a valid button in the current game context.
 * @return true if the provided buttonIndex matches the expected input and the
 *         player's progress was advanced; false if the input was incorrect.
 */
bool checkButton(int buttonIndex);

/**
 * @brief Reset the current game's score.
 *
 * Sets the global game's score to zero, effectively restarting the
 * player's score while leaving other game state fields unchanged.
 */
void reset(void);

/**
 * @brief Determines game difficulty based on input
 *
 * Reads an analog input (e.g., potentiometer) to determine
 * the current difficulty level of the game. The input value
 * is mapped to predefined difficulty settings.
 *
 * @param pin The analog pin number to read from
 * @return Integer representing difficulty level (1=easy, 2=medium, 3=hard)
 */
int difficulty(int pin);

/**
 * @brief Controls LED fade animation
 *
 * Creates a smooth fading effect on an LED using PWM.
 * Useful for visual feedback and game animations.
 *
 * @param pin The PWM-capable pin controlling the LED
 */
void ledFade(int pin);

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
bool wasPressed(int pin);

#endif