
#ifndef LCD_H
#define LCD_H

#include "ILcd.h"

/**
 * @brief Concrete ILcd implementation using LiquidCrystal_I2C.
 *
 * Uses a 16x2 (default) character LCD over I2C.
 */
class Lcd : public ILcd {
  public:
    Lcd();

    /**
     * @brief Print a message on the given row (zero-based).
     *
     * This implementation clamps the row to the available display rows and
     * truncates the message to the display width.
     */
    void print(int row, const String message);

    /**
     * @brief Clear the display.
     */
    void clear();
};

#endif