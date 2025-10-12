#ifndef OUTPUT_H
#define OUTPUT_H

/**
 * @file output.h
 * @brief Simple output helpers for the platform (Arduino-style environment).
 *
 * These functions provide a minimal interface for initializing and writing
 * textual output. The implementation is expected to be platform-specific
 * (for example writing to Serial on Arduino).
 */

/**
 * Initialize the output subsystem.
 *
 * This must be called before any other output functions. On Arduino this
 * typically calls `Serial.begin(baud)` or performs other platform specific
 * initialization.
 */
void outputInit(void);

/**
 * Print a null-terminated string to the output device.
 *
 * @param message A NUL-terminated C string to send to the output.
 *                The function does not take ownership of the pointer.
 */
void print(char *message);

/**
 * Clear the output, if supported by the platform.
 *
 * On many platforms this is a no-op. When available it should clear the
 * display or reset the console state.
 */
void clear(void);

#endif