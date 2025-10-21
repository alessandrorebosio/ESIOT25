#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include "output.h"

static LiquidCrystal_I2C lcd(LCD_ADDR, LCD_COLS, LCD_ROWS);

/**
 * Print text to a specific LCD line with optional centering
 * 
 * @param line The line number (0-based)
 * @param message The text to display
 * 
 * @note The line will be cleared before printing
 * @note Text will be padded with spaces to ensure clean display
 * @private
 */
static inline void printLine(uint8_t line, const String &message) {
    if (line >= LCD_ROWS) return;

    char buf[LCD_COLS + 1];
    size_t len = message.length();
    if (len > LCD_COLS) len = LCD_COLS;

    message.toCharArray(buf, len + 1);

    for (size_t i = len; i < LCD_COLS; ++i) buf[i] = ' ';
    buf[LCD_COLS] = '\0';

    lcd.setCursor(0, line);
    lcd.print(buf);
}

/**
 * Initialize the output subsystem
 * 
 * Sets up the LCD display, enables backlight, and clears the screen.
 * This function must be called before any output operations.
 */
void outputInit() { 
    lcd.init();
    lcd.backlight();
    lcd.clear();
}

/**
 * Print a message to the LCD display
 * 
 * Supports multi-line messages using newline characters and optional
 * text centering for better visual presentation.
 * 
 * @param message The string to display
 */
void print(const String message) {
    int newlinePos = message.indexOf('\n');
    
    if (newlinePos != -1) {
        printLine(0, message.substring(0, newlinePos));
        printLine(1, message.substring(newlinePos + 1));
    } else {
        printLine(0, message);
        printLine(1, "");
    }
}

/**
 * Clear the entire LCD display
 * 
 * Resets both lines to blank and returns cursor to position (0,0).
 * Uses the LiquidCrystal_I2C library's clear function.
 */
void clear(void) { lcd.clear(); }
