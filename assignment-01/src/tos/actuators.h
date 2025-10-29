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
 */

/**
 * @brief Represents a button with software debouncing support.
 *
 * This structure stores the button state readings and timing information
 * required for debouncing. It is intended for buttons wired as active LOW, 
 * but can also work with active HIGH configurations if logic is adjusted
 * accordingly.
 */
struct Button {
    uint8_t pin;
    int rawReading = HIGH;
    int lastReading = HIGH;
    unsigned long lastTime = 0;

    Button(uint8_t p) : pin(p) {}
};

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