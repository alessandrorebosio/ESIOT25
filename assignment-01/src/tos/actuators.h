#ifndef INPUT_H
#define INPUT_H

#include <Arduino.h>

/**
 * @file actuators.h
 * @brief Input/actuator helpers for buttons, potentiometer and LEDs.
 *
 * This module exposes a small API to initialize and query button inputs
 * (with debouncing), read a potentiometer used for difficulty selection
 * and perform simple LED operations such as fading and turning off all
 * LEDs.
 *
 * Note: this header name and include guard use `INPUT_H` for historical
 * reasons; the implementation file is `actuators.cpp` and the public API
 * functions are named accordingly.
 */

/**
 * @brief Initialize the input and actuator subsystem.
 *
 * Configures sequence button pins and their corresponding LED pins.
 * Also configures the potentiometer pin. This function should be called
 * once during system initialization before any input/output operations.
 */
void actuatorsInit();

/**
 * @brief Check whether a button was pressed since the last call.
 *
 * Performs edge detection and software debouncing. The function returns
 * true on the falling edge (button transition from HIGH to LOW) and
 * will suppress bounces for the configured debounce interval.
 *
 * @param pin Digital pin number to check.
 * @return true if a valid press was detected since the last call.
 *
 * @note Assumes active-LOW button wiring (button connects the input to
 * ground when pressed).
 */
bool wasPressed(const uint8_t pin);

/**
 * @brief Read and map the potentiometer value to a 1..LIMIT range.
 *
 * Reads the specified analog pin and maps the ADC value to the game
 * difficulty range (1..LIMIT).
 *
 * @param pin Analog pin number where the potentiometer is connected.
 * @return Mapped potentiometer value (1..LIMIT).
 */
uint8_t mapPotentiometer(const uint8_t pin);

/**
 * @brief Perform a non-blocking fade animation on the given PWM-capable pin.
 *
 * Call this frequently from the main loop; the function tracks timing
 * and updates brightness only when required.
 *
 * @param pin PWM-capable digital pin to animate.
 */
void ledFade(int pin);

/**
 * @brief Turn off all LEDs used by the game (sequence LEDs + status LED).
 *
 * This function sets every sequence LED to LOW and also turns off the
 * status LED. It is useful when leaving a game state or as a cleanup step.
 */
void turnOffAllLEDs();

#endif