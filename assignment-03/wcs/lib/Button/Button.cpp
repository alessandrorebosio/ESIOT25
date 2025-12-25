#include "Button.h"

/**
 * @brief Constructs a Button object and initializes the pin.
 * 
 * @param pin The digital pin number to which the button is connected.
 * @param mode The pin mode (e.g., INPUT, INPUT_PULLUP).
 */
Button::Button(const uint8_t pin, const uint8_t mode) : pin(pin) {
    pinMode(this->pin, mode);
}

/**
 * @brief Returns whether the button is currently pressed.
 * 
 * This method returns the last updated pressed state, which is updated by sync().
 * 
 * @return true if the button is pressed, false otherwise.
 */
bool Button::isPressed(void) {
    return this->pressed;
}

/**
 * @brief Synchronizes the button state with the physical pin.
 * 
 * Updates the internal pressed and clicked flags based on the current digital read.
 * A click is registered when the button is released after being pressed.
 */
void Button::sync() {
    bool wasPressed = pressed;
    pressed = digitalRead(pin) == HIGH;
    if (!pressed) {
        if (wasPressed) {
            clicked = true;
        } else {
            if (clicked) {
                clicked = false;
            }
        }
    } else if (pressed) {
        clicked = false;
    }
}
