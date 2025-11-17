#ifndef IBUTTON_H
#define IBUTTON_H

#include <Arduino.h>

/**
 * @brief Interface for a digital push-button.
 *
 * Implementations provide debounced press detection. The `isPressed`
 * method should be non-blocking and return true when a valid press
 * event (after debouncing) is detected.
 */
class IButton {
  public:
    /**
     * @brief Check whether the button was pressed.
     *
     * This method returns true when a debounced press is detected.
     * It does not block waiting for a press; instead it should be
     * called repeatedly (for example from a loop) to detect press
     * events.
     *
     * @return true if a debounced press edge was detected, false otherwise
     */
    virtual bool isPressed() = 0;

    /**
     * @brief Virtual destructor for interface safety.
     */
    virtual ~IButton() = default;
};

#endif