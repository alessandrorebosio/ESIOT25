#include "Potentiometer.h"

/**
 * @brief Constructs a Potentiometer object and initializes the pin.
 * 
 * Sets the specified pin mode to INPUT for analog reading.
 * 
 * @param pin The analog pin number where the potentiometer is connected.
 */
Potentiometer::Potentiometer(uint8_t pin) : pin(pin) {
    pinMode(this->pin, INPUT);
}

/**
 * @brief Reads the current analog value from the potentiometer.
 * 
 * Performs an analog read on the configured pin and returns the raw ADC value.
 * 
 * @return int The analog reading value between 0 and 1023.
 */
int Potentiometer::read(void) {
    return analogRead(this->pin);
}
