#pragma once

#include <Arduino.h>

/**
 * @class Button
 * @brief Handles digital button input with state tracking.
 *
 * The Button class manages the state of a physical button connected to a digital pin.
 * It supports both pressed and clicked detection and requires periodic synchronization
 * to update its internal state.
 */
class Button final {
  private:
    uint8_t pin;
    bool pressed;
    bool clicked;

  public:
    /**
     * @brief Constructs a Button object and initializes the pin.
     *
     * @param pin The digital pin number to which the button is connected.
     * @param mode The pin mode (e.g., INPUT, INPUT_PULLUP).
     */
    explicit Button(uint8_t pin, uint8_t mode);

    /**
     * @brief Returns whether the button is currently pressed.
     *
     * @return true if the button is pressed, false otherwise.
     */
    bool isPressed(void);

    /**
     * @brief Synchronizes the internal button state with the physical pin.
     *
     * This method should be called periodically (e.g., in loop()) to update
     * the pressed and clicked states based on the current digital reading.
     */
    void sync(void);

    /**
     * @brief Default destructor.
     */
    ~Button() = default;
};