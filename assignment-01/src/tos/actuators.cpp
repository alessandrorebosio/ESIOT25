#include <Arduino.h>

#include "actuators.h"
#include "config.h"

extern Button BUTTONS[];
extern int LEDS[];
extern int SEQ_LEN;

/**
 * @file actuators.cpp
 * @brief Implementation of input and actuator helpers for ToS.
 *
 * This file implements debounced button reading, potentiometer mapping and
 * simple LED utilities such as fading and turning off all LEDs.
 */

/** Timestamp of last fade update (internal state). */
static unsigned long lastFadeUpdate = 0;

/** Current brightness used by ledFade(). */
static int brightness = FADE_INITIAL_BRIGHTNESS;

/** Fade step applied to brightness on each fade update. */
static int fadeAmount = FADE_INITIAL_AMOUNT;

/**
 * @brief Initialize all input and actuator pins.
 *
 * Configures the sequence button pins and the corresponding LED pins.
 * Also configures the potentiometer analog pin. The exact pin mode
 * (INPUT vs INPUT_PULLUP) must match the physical wiring: this code
 * sets button pins to INPUT and assumes external pull-ups or hardware
 * wiring that provides a stable HIGH idle state.
 *
 * @note The status LED identifier used in this file is `LSLED` (legacy).
 * The project-wide name defined in `config.h` is `LSLED_PIN`. Ensure the
 * two identifiers match in the code base; otherwise update references.
 */
void actuatorsInit() {
    for (int i = 0; i < SEQ_LEN; i++) {
        pinMode(BUTTONS[i].pin, INPUT);
        pinMode(LEDS[i], OUTPUT);
    }
    pinMode(POTENTIOMETER_PIN, INPUT);
    pinMode(LSLED, OUTPUT);
}

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
Button button(const uint8_t pin) { return {pin, HIGH, HIGH, 0}; }

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
bool isPressed(Button &button) {
    int reading = digitalRead(button.pin);
    unsigned long currentTime = millis();

    if (reading != button.rawReading) {
        button.rawReading = reading;
        button.lastTime = currentTime;
    }

    if ((currentTime - button.lastTime) > DEBOUNCE_TIME) {
        if (button.rawReading != button.lastReading) {
            button.lastReading = button.rawReading;
            return button.lastReading == LOW;
        }
    }

    return false;
}

/**
 * @brief Map the potentiometer analog reading into the game difficulty range.
 *
 * Reads the ADC value from `pin`, then maps it into the integer range
 * [1..LIMIT] where `LIMIT` is the number of difficulty levels.
 *
 * @param pin Analog pin to read (e.g., POTENTIOMETER_PIN).
 * @return Mapped difficulty value in 1..LIMIT.
 */
uint8_t mapPotentiometer(const uint8_t pin) {
    return (uint8_t)map(analogRead(pin), 0, ANALOG_MAX_VALUE, 1, LIMIT);
}

/**
 * @brief Perform a non-blocking fade animation on the specified PWM pin.
 *
 * This function updates the brightness on `pin` only when the internal
 * timer indicates that FADE_INTERVAL milliseconds have elapsed. Call it
 * frequently from the main loop.
 *
 * @param pin PWM-capable digital pin.
 */
void ledFade(const uint8_t pin) {
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
 * @brief Turn off all game LEDs (sequence LEDs and status LED).
 *
 * Sets each LED in the sequence to LOW and also writes LOW to the
 * status LED pin.
 */
void turnOffAllLEDs() {
    for (int i = 0; i < SEQ_LEN; i++) {
        digitalWrite(LEDS[i], LOW);
    }
    digitalWrite(LSLED, LOW);
}