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
 * @brief Data structure representing the runtime state of a button input.
 *
 * This struct stores information needed to read, debounce and track changes
 */
struct Button {
    uint8_t pin;
    int lastReading;
    int rawReading;
    unsigned long lastTime;
};

/**
 * @brief Create a Button instance bound to a specific GPIO pin.
 *
 * Constructs and returns a Button object configured to read the digital input
 * on the given pin. The returned object represents the button connected to that
 * pin and can be used with the Button class' polling or event APIs.
 *
 * @param pin The microcontroller pin number where the button is connected.
 * @return Button A Button instance associated with the specified pin.
 */
Button button(const uint8_t pin);

/**
 * @brief Initialize the input and actuator subsystem.
 *
 * Configures sequence button pins and their corresponding LED pins.
 * Also configures the potentiometer pin. This function should be called
 * once during system initialization before any input/output operations.
 */
void actuatorsInit();

/**
 * @brief Determine whether the specified Button is currently pressed.
 *
 * Reads the state of the provided Button object and returns true when the
 * button is considered to be in a pressed state. The call may update the Button
 * instance (for example to perform debouncing or state bookkeeping), therefore
 * a non-const reference is required.
 *
 * @param button Reference to the Button to query. The caller must ensure the
 * object remains valid for the duration of the call.
 * @return true if the button is currently pressed, false otherwise.
 */
bool isPressed(Button &button);

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
void ledFade(const uint8_t pin);

/**
 * @brief Turn off all LEDs used by the game (sequence LEDs + status LED).
 *
 * This function sets every sequence LED to LOW and also turns off the
 * status LED. It is useful when leaving a game state or as a cleanup step.
 */
void turnOffAllLEDs();

#endif