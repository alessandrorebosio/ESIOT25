#include <Arduino.h>
#include "input.h"
#include "logic.h"
#include "config.h"

/**
 * @file input.cpp
 * @brief Implementation of input handling for button and potentiometer
 * 
 * This file contains the debouncing logic for button presses and
 * analog reading for difficulty selection via potentiometer.
 */
const unsigned long debounceDelay = 50;

/**
 * @brief Initialize all input pins
 * 
 * Configures button pins as digital inputs without pull-up resistors
 * (external pull-ups assumed) and potentiometer pin as analog input.
 * Must match the physical circuit configuration.
 */
void inputInit() {
    for (int i = 0; i < SEQ_LEN; i++) {
        pinMode(BUTTONS[i], INPUT);
    }
    pinMode(POTENTIOMETER_PIN, INPUT);
}

/**
 * @brief Check for button press with debouncing
 * 
 * Implements a state-based debouncing algorithm that requires the button
 * to maintain a stable LOW state for the debounce delay before registering
 * as a press. Uses static arrays to maintain state for up to 20 pins.
 * 
 * @param pin The digital pin number to check
 * @return bool True if a valid press is detected, false otherwise
 * 
 * @note Assumes active LOW button configuration (button connects to ground when pressed)
 * @note Returns false immediately for invalid pin numbers (>= 20)
 * @note Maintains separate state for each pin independently
 */
bool wasPressed(const uint8_t pin) {
    if (pin >= 20)
        return false;

    static int lastButtonState[20] = {HIGH};
    static int buttonState[20] = {HIGH};
    static unsigned long lastDebounceTime[20] = {0};

    int reading = digitalRead(pin);
    unsigned long now = millis();

    if (reading != lastButtonState[pin]) {
        lastDebounceTime[pin] = now;
    }

    if ((now - lastDebounceTime[pin]) > debounceDelay) {
        if (reading != buttonState[pin]) {
            buttonState[pin] = reading;
            if (buttonState[pin] == LOW) {
                lastButtonState[pin] = reading;
                return true;
            }
        }
    }

    lastButtonState[pin] = reading;
    return false;
}

/**
 * @brief Read potentiometer and set game difficulty
 * 
 * Reads the analog value from the potentiometer and maps it to the
 * configured difficulty range. The mapping uses Arduino's map() function
 * to convert from analog range [0, ANALOG_MAX_VALUE] to difficulty
 * range [ONE, LIMIT].
 * 
 * @param game Pointer to the Game structure to update
 * @param pin Analog pin number connected to the potentiometer
 * 
 * @note Does nothing if game pointer is NULL
 * @note Difficulty levels are defined by ONE and LIMIT constants
 * @note ANALOG_MAX_VALUE is typically 1023 for 10-bit ADC
 */
void setDifficulty(Game *game, const uint8_t pin) {
    if (!game)
        return;
    int v = analogRead(pin);
    game->difficulty = (uint8_t)map(v, 0, ANALOG_MAX_VALUE, ONE, LIMIT);
}
