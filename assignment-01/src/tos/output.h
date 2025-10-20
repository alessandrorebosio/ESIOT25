#ifndef OUTPUT_H
#define OUTPUT_H

/**
 * @file output.h
 * @brief LCD output handling functions
 */
void outputInit(void);

/**
 * @brief Prints a message to the LCD display.
 * 
 * If the message contains a newline character ('\n'), it splits the message
 * across two lines. If either line exceeds the display width (16 characters),
 * it scrolls the text automatically.
 * 
 * @param message The message to print. If it contains a newline character ('\n'),
 *                the message will be split across two lines. If either line exceeds
 *                the display width (16 characters), it will be scrolled automatically.
 */
void print(const String &message);

/**
 * @brief Clears the entire LCD display
 * 
 * This function clears both lines of the display and returns the cursor
 * to the home position (0,0).
 */
void clear(void);

#endif