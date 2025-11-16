#ifndef LED_H
#define LED_H

#include <Arduino.h>

/**
 * @file Led.h
 * @brief Utility functions to manage a LED on Arduino.
 *
 * Provides simple functions to turn a LED on, turn it off, and
 * perform a blinking cycle on a specified digital pin.
 */

/**
 * @brief Turn the LED on at the given pin.
 * @param pin Digital pin number where the LED is connected.
 */
void turnOn(const uint8_t pin);

/**
 * @brief Turn the LED off at the given pin.
 * @param pin Digital pin number where the LED is connected.
 */
void turnOff(const uint8_t pin);

/**
 * @brief Perform a single blink cycle (on -> off) using a fixed period.
 * @param pin Digital pin number where the LED is connected.
 *
 * Note: The blink period is defined in `Led.cpp` by the `PERIOD` macro (ms).
 * This function is blocking because it uses `delay()`.
 */
void blinking(const uint8_t pin);

#endif