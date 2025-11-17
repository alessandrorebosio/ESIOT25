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
    uint8_t lastReading = HIGH;
    uint8_t rawReading = HIGH;
    uint8_t pin;

  public:
    /**
     * @brief Check whether the button was pressed (debounced).
     *
     * @return true if a debounced press edge was detected, false otherwise
     */
    bool isPressed();
};
