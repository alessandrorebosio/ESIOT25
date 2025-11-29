#pragma once

#include <Arduino.h>

/**
 * @brief Button class for handling digital button input.
 *
 * This class provides a simple interface for reading the state of a digital button.
 * It handles pin initialization and state reading.
 */
class Button final {
  private:
    uint8_t pin;

  public:
    /**
     * @brief Constructs a Button object and initializes the pin.
     *
     * @param pin The digital pin number where the button is connected
     * @param mode The pin mode (INPUT, INPUT_PULLUP, etc.)
     */
    explicit Button(uint8_t pin, uint8_t mode);

    /**
     * @brief Checks if the button is currently pressed.
     *
     * @return true if the button is pressed, false otherwise
     */
    bool isPressed(void);

    /**
     * @brief Default destructor.
     */
    ~Button() = default;
};
