#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#include "output.h"
#include "config.h"

/**
 * @file output.cpp
 * @brief Output management implementation for LCD and LED controls
 * 
 * Handles all display output operations including LCD text rendering
 * and LED visual effects for the ToS game system.
 */
static LiquidCrystal_I2C lcd(LCD_ADDR, LCD_COLS, LCD_ROWS);

const unsigned long FADE_INTERVAL = 15;
static unsigned long lastFadeUpdate = 0;
static int brightness = 0;
static int fadeAmount = 5;

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
    if (line >= LCD_ROWS)
        return;

    char buf[LCD_COLS + 1];
    size_t len = message.length();
    if (len > LCD_COLS)
        len = LCD_COLS;

    message.toCharArray(buf, len + 1);

    for (size_t i = len; i < LCD_COLS; ++i)
        buf[i] = ' ';
    buf[LCD_COLS] = '\0';

    lcd.setCursor(0, line);
    lcd.print(buf);
}

/**
 * @brief Initialize the output subsystem
 * 
 * Sets up the LCD display with I2C communication, enables backlight,
 * clears the screen, and configures all LED pins as digital outputs.
 * This function must be called once during system initialization.
 */
void outputInit() {
    lcd.init();
    lcd.backlight();
    lcd.clear();

    for (int i = 0; i < SEQ_LEN; i++) {
        pinMode(LEDS[i], OUTPUT);
    }
    pinMode(LSLED_PIN, OUTPUT);
}

/**
 * Print a message to the LCD display
 *
 * Supports multi-line messages using newline characters and optional
 * text centering for better visual presentation.
 *
 * @param message The string to display
 */
void print(const String &message) {

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

/**
 * Perform a non-blocking fade animation on the specified PWM pin.
 *
 * Call this frequently from the main loop; timing is handled internally
 * and the function returns immediately if it is not yet time to update
 * the brightness.
 *
 * @param pin PWM-capable digital pin.
 */
void ledFade(int pin) {
    unsigned long now = millis();
    if (now - lastFadeUpdate < FADE_INTERVAL)
        return;
    lastFadeUpdate = now;

    brightness += fadeAmount;
    if (brightness <= 0 || brightness >= 255) {
        fadeAmount = -fadeAmount;
        brightness = constrain(brightness, 0, 255);
    }

    analogWrite(pin, brightness);
}

/**
 * @brief Turn off all game LEDs
 * 
 * Sets all sequence LEDs (green) and status LED (red) to LOW state,
 * effectively turning them off. Used for cleanup between game states
 * and during transitions.
 */
void turnOffAllLEDs() {
    for (int i = 0; i < SEQ_LEN; i++) {
        digitalWrite(LEDS[i], LOW);
    }
    digitalWrite(LSLED_PIN, LOW);
}