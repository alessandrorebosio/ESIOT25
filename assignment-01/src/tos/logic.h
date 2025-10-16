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
 * @brief Array of button pins
 * 
 * Constant array containing the pin numbers to which the
 * game buttons are connected. The array size determines
 * the number of available buttons.
 */
extern const int BUTTON[];
const int SEQUENCE_LENGTH = 4;

/**
 * @brief Game sequence data structure
 *
 * Contains all data related to the current game sequence,
 * including the sequence values, current progress, and
 * display state.
 */
typedef struct {
    int sequence[SEQUENCE_LENGTH];    /**< Array storing the sequence of button indices */
    int length;                       /**< Current length of the active sequence */
    int currentStep;                  /**< Current position in the sequence (0-based) */
    bool isShowing;                   /**< Flag indicating if sequence is being displayed */
} GameSequence;

/**
 * @brief Generates a new random sequence
 *
 * Creates a shuffled sequence of button indices.
 * The sequence contains all numbers
 * from 0 to seqLength-1 in random order.
 *
 * @param seq Pointer to GameSequence struct to populate
 * @param seqLength The length of the sequence to generate
 */
void initSequence(GameSequence *seq, int seqLength);

/**
 * @brief Shuffles the existing sequence
 *
 * Randomly rearranges the elements of the current sequence
 * to create a new order without changing its length.
 *
 * @param seq Pointer to GameSequence struct to shuffle
 */
void shuffleSequence(GameSequence *seq);

/**
 * @brief Prints sequence to serial monitor
 *
 * Displays the current sequence in a human-readable format
 * on the serial monitor for debugging and player reference.
 *
 * @param seq Pointer to GameSequence struct to display
 */
void printSequence(const GameSequence *seq);

/**
 * @brief Checks player's input against the sequence
 *
 * Compares the button index pressed by the player with
 * the expected value in the sequence. Advances the
 * current step if correct.
 *
 * @param seq Pointer to GameSequence struct containing current game state
 * @param buttonIndex The index of the button that was pressed (0-based)
 * @return true if button matches current sequence step, false otherwise
 */
bool checkPlayerInput(GameSequence *seq, int buttonIndex);

/**
 * @brief Resets sequence progress
 *
 * Sets currentStep back to 0, allowing the same sequence
 * to be re-attempted or marking the sequence as no longer being displayed.
 *
 * @param seq Pointer to GameSequence struct to reset
 */
void resetSequence(GameSequence *seq);

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
 * @brief Checks if a button was pressed
 * 
 * Detects whether a specific button has been pressed
 * since the last check. Includes debouncing logic to
 * prevent false triggers.
 * 
 * @param index The index of the button in the BUTTON array
 * @return true if the button was pressed, false otherwise
 */
bool wasPressed(int index);

#endif