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

/**
 * @brief Generates a random number sequence
 * 
 * Creates an array of random integers within the range of
 * available buttons. The sequence represents the pattern
 * that the player must replicate.
 * 
 * @param size The length of the sequence to generate
 * @return Pointer to dynamically allocated array containing the sequence
 * @note The caller is responsible for freeing the memory
 */
int *sequence(int size);

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