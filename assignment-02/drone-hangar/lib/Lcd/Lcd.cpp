#include "Lcd.h"

#define LCD_ADDR 0x27
#define LCD_COLS 16
#define LCD_ROWS 2

LiquidCrystal_I2C lcd(LCD_ADDR, LCD_COLS, LCD_ROWS);

Lcd::Lcd() {
    lcd.init();
    lcd.backlight();
    lcd.clear();
}

/**
 * @brief Print a message on the specified row of the LCD.
 *
 * The row index is zero-based (0 = top). Values outside [0, LCD_ROWS-1]
 * are clamped. Messages longer than the display width are truncated.
 */
void Lcd::print(int row, const String message) {
    if (row < 0)
        row = 0;
    if (row >= LCD_ROWS)
        row = LCD_ROWS - 1;

    String msg = message;
    if (msg.length() > LCD_COLS) {
        msg = msg.substring(0, LCD_COLS);
    }

    lcd.setCursor(0, row);
    lcd.print(msg);
}

/**
 * @brief Clear the display.
 */
void Lcd::clear() { lcd.clear(); }
