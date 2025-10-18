#ifndef OUTPUT_H
#define OUTPUT_H

#define LCD_ADDR 0x27
#define LCD_COLS 16
#define LCD_ROWS 2

/**
 * @file output.h
 * @brief LCD output management with text centering capabilities
 */

/**
 * Initialize the LCD output subsystem
 * 
 * This function must be called before any other output operations.
 * It initializes the I2C LCD display and turns on the backlight.
 */
void outputInit(void);

/**
 * Print a message to the LCD display
 * 
 * @param message The string to display. Use '\n' to split text across two lines
 * 
 * @note If the message contains a newline character, the text will be split
 *       across both LCD lines. Otherwise, line 1 will be cleared.
 * @note Text longer than 16 characters will be automatically truncated
 */
void print(const String message);

/**
 * Clear the entire LCD display
 * 
 * This function clears both lines of the display and returns the cursor
 * to the home position (0,0).
 */
void clear(void);

#endif