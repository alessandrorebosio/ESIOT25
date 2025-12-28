#include "Led.h"

/**
 * @brief Constructs a Led object and initializes the pin as OUTPUT.
 * 
 * @param pin The digital pin number where the LED is connected
 */
Led::Led(const uint8_t pin) : pin(pin) {
    pinMode(this->pin, OUTPUT);
}

/**
 * @brief Turns the LED on by setting the pin to HIGH.
 */
void Led::on() {
    digitalWrite(this->pin, HIGH);
}

/**
 * @brief Turns the LED off by setting the pin to LOW.
 */
void Led::off() {
    digitalWrite(this->pin, LOW);
}
