#include "Button.h"

/**
 * @brief Constructs a Button object and initializes the pin.
 * 
 * This constructor sets up the button pin with the specified mode (INPUT, INPUT_PULLUP, etc.).
 * 
 * @param pin The digital pin number to which the button is connected.
 * @param mode The pin mode (e.g., INPUT, INPUT_PULLUP).
 */
Button::Button(const uint8_t pin, const uint8_t mode) : pin(pin) {
    pinMode(this->pin, mode);
}

/**
 * @brief Checks if the button is currently pressed.
 * 
 * This function reads the digital state of the button pin and returns true if the button is pressed.
 * Note: The logic may depend on the wiring (e.g., active high vs. active low).
 * 
 * @return true if the button is pressed, false otherwise.
 */
bool Button::isPressed(void) {
    return digitalRead(pin);
}
