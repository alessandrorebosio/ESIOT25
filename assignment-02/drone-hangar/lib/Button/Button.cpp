#include "Button.h"

#define DEBOUNCE_TIME 50

/**
 * @file Button.cpp
 * @brief Debounced digital push-button implementation.
 */

/** Debounce interval (milliseconds) used to filter mechanical bounce. */
#define DEBOUNCE_TIME 50

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
     * @brief Construct a new Button object attached to a pin.
     *
     * @param pin Arduino digital pin number where the button is connected.
     */
    Button(const uint8_t pin) { this->pin = pin; }

    /**
     * @brief Check whether the button was pressed (debounced).
     *
     * This method implements a non-blocking debounce algorithm:
     * - Read the raw pin state.
     * - If the raw state changed, reset the debounce timer.
     * - When the raw state remains stable longer than `DEBOUNCE_TIME`,
     *   consider it a valid change and report a press event when the
     *   stable state becomes `LOW` (assuming active-low wiring).
     *
     * @return true if a debounced press edge was detected, false otherwise
     */
    bool isPressed() override {
        uint8_t reading = digitalRead(this->pin);
        unsigned long currentTime = millis();

        if (reading != this->rawReading) {
            this->rawReading = reading;
            this->lastTime = currentTime;
        }

        if ((currentTime - this->lastTime) > DEBOUNCE_TIME) {
            if (this->rawReading != this->lastReading) {
                this->lastReading = this->rawReading;
                return this->lastReading == LOW;
            }
        }

        return false;
    }
};
