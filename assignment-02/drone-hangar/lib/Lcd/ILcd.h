
#ifndef ILCD_H
#define ILCD_H

#include <Arduino.h>

/**
 * @brief Interface for a simple character LCD display.
 *
 * Implementations should provide a way to print a message on a specific
 * row and to clear the display.
 */
class ILcd {
  public:
    /**
     * @brief Print a message on a given row of the display.
     *
     * @param row Zero-based row index (0 = top row). Implementations should
     * clamp the value to the display height.
     * @param message The text to display. If longer than the display width,
     * implementations may truncate it.
     */
    virtual void print(int row, String message) = 0;

    /**
     * @brief Clear the entire display.
     */
    virtual void clear() = 0;

    /**
     * @brief Virtual destructor for interface safety.
     */
    virtual ~ILcd() = default;
};

#endif