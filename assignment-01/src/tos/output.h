#ifndef OUTPUT_H
#define OUTPUT_H

/**
 * @file output.h
 * @brief Output management with text centering capabilities
 */

/**
 * Initialize the output subsystem
 *
 * This function must be called before any other output operations.
 */
void outputInit(void);

/**
 * Print a message.
 *
 * @param message The string to display. Use '\n' to split text across two
 *                lines. The string is passed by const reference to avoid
 *                needless copies.
 */
void print(const String &message);

/**
 * Clear the entire output
 *
 * This function clears all lines.
 */
void clear(void);

#endif