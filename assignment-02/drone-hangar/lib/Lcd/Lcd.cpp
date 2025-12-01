#include "Lcd.h"

/**
 * @brief Constructs an Lcd object and initializes the display.
 *
 * This constructor creates a new LiquidCrystal_I2C instance, initializes the display,
 * turns on the backlight, and clears the display.
 *
 * @param address I2C address of the LCD display
 * @param cols Number of columns in the display
 * @param rows Number of rows in the display
 */
Lcd::Lcd(const uint8_t address, const uint8_t cols, const uint8_t rows) {
    this->lcd = new LiquidCrystal_I2C(address, cols, rows);
    this->lcd->init();
    this->lcd->backlight();
    this->clear();
}

/**
 * @brief Prints text to the LCD display.
 *
 * This method clears the display, sets cursor to the home position (0,0),
 * and prints the provided text.
 *
 * @param y Row position (0-based)
 * @param text The string to be displayed
 */
void Lcd::print(const uint8_t y, const String text) {
    // this->clear();
    this->setCursor(0, y);
    this->lcd->print(text);
}

/**
 * @brief Sets the cursor position on the LCD display.
 *
 * @param x Column position (0-based)
 * @param y Row position (0-based)
 */
void Lcd::setCursor(const uint8_t x, const uint8_t y) {
    this->lcd->setCursor(x, y);
}

/**
 * @brief Destructor that deallocates the LiquidCrystal_I2C instance.
 *
 * This destructor is required to prevent memory leaks since the constructor
 * uses dynamic memory allocation (new) to create the LiquidCrystal_I2C object.
 * Without this explicit destructor, the dynamically allocated memory would not be freed.
 */
void Lcd::clear() {
    this->lcd->clear();
}
