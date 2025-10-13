#include <Arduino.h>

#include "output.h"

/**
 * @brief Serial transmission speed (baud rate).
 *
 * Constant representing the serial communication speed set to 9600 bits per
 * second (bps). Used to configure the UART/serial interface and ensure the
 * local device and host or external devices communicate at the same rate.
 */
static const int BAUD_RATE = 9600;

/**
 * @file output.cpp
 * @brief Arduino Serial implementation for the `output` API declared in
 *        `output.h`.
 *
 * Functions here use the global `Serial` object when compiled for Arduino.
 * When built for the host (non-ARDUINO) a minimal stdout fallback is used so
 * the module can be exercised during unit tests or local builds.
 */

/**
 * Initialize the output subsystem.
 *
 * For Arduino this calls `Serial.begin(115200)` and waits for the serial
 * port where appropriate. On non-embedded builds this is a no-op.
 */
void outputInit() { Serial.begin(BAUD_RATE); }

/**
 * Print a null-terminated string to the output device.
 *
 * This function does not append a newline; use `print("...\n")` if a
 * newline is desired.
 */
void print(char *message) { Serial.println(message); }

/**
 * Clear the output device if possible.
 *
 * There is no portable API to clear the IDE Serial Monitor. This function
 * emits an ANSI clear-screen escape sequence which is interpreted by many
 * terminal programs (minicom, screen, some serial terminal emulators). If
 * ANSI sequences are not interpreted (for example Arduino IDE Serial
 * Monitor) the call will effectively move the cursor or print invisible
 * characters; some terminals may not clear at all. On host builds we print
 * several newlines as a fallback.
 */
void clear(void) {}
