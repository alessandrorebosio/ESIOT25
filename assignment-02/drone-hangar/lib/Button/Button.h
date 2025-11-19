#ifndef BUTTON_H
#define BUTTON_H

#include "IButton.h"

/**
 * @file Button.cpp
 * @brief Debounced digital push-button implementation.
 */

/**
 * @brief Concrete implementation of `IButton` for a digital input pin.
 *
 * This class implements a simple edge-detection debouncer. Call
 * `isPressed()` frequently (for example inside `loop()`) to detect
 * press events. The implementation returns true only once when a
 * debounced press edge is observed.
 */
class Button : public IButton {
  private:
    unsigned long lastTime = 0;
    uint8_t lastReading = LOW;
    uint8_t rawReading = LOW;
    uint8_t pin;

  public:
    /**
     * @brief Construct a Button instance bound to a pin.
     * @param pin Digital pin used for the button signal.
     */
    Button(uint8_t pin);

    /**
     * @brief Initialize the button hardware and internal debouncer.
     *
     * This method should configure the input pin (e.g., via `pinMode`)
     * and reset any internal state required by the debounce algorithm.
     * Call this once during system setup before using `isPressed()`.
     */
    void begin();

    /**
     * @brief Check whether the button was pressed (debounced).
     *
     * @return true if a debounced press edge was detected, false otherwise
     */
    bool isPressed();
};

#endif