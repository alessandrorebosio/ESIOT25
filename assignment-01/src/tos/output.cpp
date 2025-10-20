#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "output.h"

/**
 * @file output.cpp
 * @brief LCD output utilities with optional scrolling for long text
 *
 * This module provides a small API to initialize and print text to a 16x2
 * I2C LCD (LiquidCrystal_I2C). Features:
 *  - print(const String &): prints text, supports a single '\n' to split
 *    content across the two lines.
 *  - scrolling: if a line is longer than the display width (16 columns),
 *    the library will automatically scroll that line. Scrolling is a
 *    blocking operation that uses delay(), so if you need non-blocking
 *    behaviour consider implementing a stateful, millis()-based variant.
 */
#define LCD_ADDR 0x27
#define LCD_COLS 16
#define LCD_ROWS 2

static LiquidCrystal_I2C lcd(LCD_ADDR, LCD_COLS, LCD_ROWS);

/**
 * @brief Prints a line of text to the specified LCD row
 * 
 * @param line The line number (0 or 1) to print to
 * @param message The text to display. If longer than LCD_COLS, it will be truncated.
 *                If shorter, it will be padded with spaces.
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
 * @brief Scrolls two lines of text simultaneously on both LCD rows
 * 
 * @param text1 The text to scroll on the first line (row 0)
 * @param text2 The text to scroll on the second line (row 1)
 * @param delayMs The delay in milliseconds between each scroll step
 * 
 * @note Both texts scroll together in sync. The scrolling continues until the
 *       longer of the two texts has completely scrolled through.
 * @note This is a blocking function that uses delay().
 */
static void scrollBothTexts(const String &text1, const String &text2, unsigned int delayMs = 400) {
    String scrollBuffer1 = text1 + "    ";
    String scrollBuffer2 = text2 + "    ";
    size_t maxLength = max(text1.length(), text2.length());
    
    for (size_t i = 0; i <= maxLength; i++) {
        String window1 = scrollBuffer1.substring(i, i + LCD_COLS);
        String window2 = scrollBuffer2.substring(i, i + LCD_COLS);
        
        printLine(0, window1);
        printLine(1, window2);
        delay(delayMs);
    }
    
    printLine(0, text1.substring(0, LCD_COLS));
    printLine(1, text2.substring(0, LCD_COLS));
}

/**
 * @brief Scrolls a single line of text on the specified LCD row
 * 
 * @param text The text to scroll
 * @param line The line number (0 or 1) to scroll on
 * @param delayMs The delay in milliseconds between each scroll step
 * 
 * @note If the text is shorter than or equal to LCD_COLS, it is displayed normally.
 * @note This is a blocking function that uses delay().
 */
static void scrollText(const String &text, uint8_t line, unsigned int delayMs = 400) {
    if (text.length() <= LCD_COLS) {
        printLine(line, text);
        return;
    }

    String scrollBuffer = text + "    ";
    
    for (size_t i = 0; i <= text.length(); i++) {
        String window = scrollBuffer.substring(i, i + LCD_COLS);
        printLine(line, window);
        delay(delayMs);
    }

    printLine(line, text.substring(0, LCD_COLS));
}

/**
 * @brief Initializes the LCD display
 * 
 * This function must be called before any other output operations.
 * It initializes the I2C LCD display, turns on the backlight, and clears the display.
 */
void outputInit() {
    lcd.init();
    lcd.backlight();
    lcd.clear();
}

/**
 * @brief Prints a message to the LCD display with automatic scrolling for long text
 * 
 * @param message The message to print. If it contains a newline character ('\n'),
 *                the message will be split across two lines. If either line exceeds
 *                the display width (16 characters), it will be scrolled automatically.
 */
void print(const String &message) {
    int newlinePos = message.indexOf('\n');
    String line1 = (newlinePos != -1) ? message.substring(0, newlinePos) : message;
    String line2 = (newlinePos != -1) ? message.substring(newlinePos + 1) : "";
    
    bool scrollLine1 = line1.length() > LCD_COLS;
    bool scrollLine2 = line2.length() > LCD_COLS;
    
    printLine(0, line1.substring(0, LCD_COLS));
    printLine(1, line2.substring(0, LCD_COLS));
    
    if (scrollLine1 && scrollLine2) {
        scrollBothTexts(line1, line2);
    } else {
        if (scrollLine1) scrollText(line1, 0);
        if (scrollLine2) scrollText(line2, 1);
    }
}

/**
 * @brief Clears the entire LCD display
 * 
 * This function clears both lines of the display and returns the cursor
 * to the home position (0,0).
 */
void clear(void) { lcd.clear(); }
