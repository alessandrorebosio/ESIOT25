#pragma once

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

/**
 * @brief LCD display controller class using I2C communication.
 *
 * This class provides a simplified interface for controlling an I2C LCD
 * display. It wraps the LiquidCrystal_I2C library with basic display
 * operations.
 */
class Lcd final {
  private:
    LiquidCrystal_I2C *lcd;

    uint8_t cols;
    uint8_t rows;

  public:
    /**
     * @brief Constructs an Lcd object and initializes the display.
     *
     * @param address I2C address of the LCD display
     * @param cols Number of columns in the display
     * @param rows Number of rows in the display
     */
    Lcd(uint8_t address, uint8_t cols, uint8_t rows);

    /**
     * @brief Prints text to the LCD display.
     *
     * This method clears the display, sets cursor to (0,0), and prints the
     * text.
     *
     * @param y Row position (0-based)
     * @param text The string to be displayed
     */
    void print(const uint8_t y, String text);

    /**
     * @brief Sets the cursor position on the LCD display.
     *
     * @param x Column position (0-based)
     * @param y Row position (0-based)
     */
    void setCursor(uint8_t x, uint8_t y);

    /**
     * @brief Clears the entire LCD display.
     */
    void clear();

    /**
     * @brief Clears a specific line of the LCD display
     *
     * Fills the specified row with spaces to clear any existing text
     *
     * @param y Row position to clear (0-based)
     */
    void clearLine(const uint8_t y);

    /**
     * @brief Default destructor.
     */
    ~Lcd() = default;
};
