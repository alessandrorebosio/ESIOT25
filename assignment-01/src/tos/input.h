#ifndef INPUT_H
#define INPUT_H

#include "logic.h"
/**
 * @file input.h
 * @brief Input handling for button presses and analog input
 * 
 * This module manages all user input operations including button state
 * detection and analog potentiometer reading for difficulty selection.
 */

/**
 * @brief Initialize the input subsystem
 * 
 * Configures all button pins as inputs with pull-up resistors and
 * sets up any necessary analog input configurations. This function
 * must be called once during system initialization before any input
 * operations are performed.
 */
void inputInit();

/**
 * @brief Check if a button was pressed since last check
 * 
 * Implements edge detection to identify button press events while
 * handling debouncing. Returns true only on the falling edge when
 * the button transitions from high to low (press detected).
 * 
 * @param pin The digital pin number to check for button press
 * @return bool True if the button was pressed since last call, false otherwise
 * 
 * @note Includes software debouncing to prevent multiple detections
 */
bool wasPressed(const uint8_t pin);

/**
 * @brief Set game difficulty based on potentiometer reading
 * 
 * Reads the analog value from the specified potentiometer pin and
 * maps it to the game's difficulty levels. Updates the game structure
 * with the selected difficulty setting.
 * 
 * @param game Pointer to the Game structure to update with difficulty
 * @param pin The analog pin number connected to the potentiometer
 */
void setDifficulty(Game *game, const uint8_t pin);

#endif