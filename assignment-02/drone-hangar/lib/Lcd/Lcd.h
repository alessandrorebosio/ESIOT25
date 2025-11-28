#pragma once

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

/**
 * @brief LCD display controller class using I2C communication.
 * 
 * This class provides a simplified interface for controlling an I2C LCD display.
 * It wraps the LiquidCrystal_I2C library with basic display operations.
 */
class Lcd final {
  private:
    LiquidCrystal_I2C *lcd;

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
     * This method clears the display, sets cursor to (0,0), and prints the text.
     * 
     * @param text The string to be displayed
     */
    void print(String text);

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
     * @brief Destructor that deallocates the LiquidCrystal_I2C instance.
     * 
     * This destructor is necessary to prevent memory leaks because the class
     * dynamically allocates a LiquidCrystal_I2C object in the constructor.
     * It ensures proper cleanup when the Lcd object is destroyed.
     */
    ~Lcd();
};
