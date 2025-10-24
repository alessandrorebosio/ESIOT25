#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

#include "utils.h"

/**
 * @file config.h
 * @brief Hardware pin assignments and timing constants for ToS (Test of
 * Sequence)
 *
 * This header centralizes the board-specific configuration used by the
 * ToS game. It defines digital/analog pin numbers, timing constants (in
 * milliseconds), array views for buttons and LEDs, and a small set of
 * numeric helper macros used across the codebase.
 *
 * Notes / assumptions:
 * - `util.h` is expected to provide helper macros such as `MIN(x,y)` and
 *   `LEN(array)` used below. If those are not present, adjust accordingly.
 * - Timing constants use the same time unit as Arduino's `millis()` (ms).
 */

/**
 * ------------------------------
 * Physical pin assignments (highest importance)
 * ------------------------------
 * These macros map logical game resources to physical Arduino pins. Keep
 * pin assignments together so wiring and board layout are easy to verify.
 */

/** Sequence button input pins (digital) */
#define BUTTON0 2
#define BUTTON1 3
#define BUTTON2 4
#define BUTTON3 5

/** LEDs corresponding to the buttons (digital outputs) */
#define LED0 6
#define LED1 7
#define LED2 8
#define LED3 9

/** Status / large indicator LED pin */
#define LSLED 10

/**
 * Optional LCD configuration (I2C) used by the UI layer. If unused,
 * these macros may be ignored by higher-level code.
 */
#define LCD_ADDR 0x27
#define LCD_COLS 16
#define LCD_ROWS 2

/** Potentiometer analog input pin (difficulty / parameter knob) */
#define POTENTIOMETER_PIN A0

/**
 * ------------------------------
 * Grouped arrays and derived values
 * ------------------------------
 * Keep array definitions adjacent to pin definitions so their relationship
 * is obvious. `SEQ_LEN` is computed from these arrays and should be placed
 * immediately after them.
 */
static const int BUTTONS[] = {BUTTON0, BUTTON1, BUTTON2, BUTTON3};
static const int LEDS[] = {LED0, LED1, LED2, LED3};

/** Number of usable sequence elements (min of buttons and LEDs). Relies on
 * helper macros `MIN` and `LEN` expected to be provided by `utils.h`.
 */
#define SEQ_LEN MIN(LEN(BUTTONS), LEN(LEDS))

/**
 * ------------------------------
 * Analog and numeric constants (medium importance)
 * ------------------------------
 */

/** Maximum ADC reading for 10-bit ADC (analogRead) */
#define ANALOG_MAX_VALUE 1023

/** Number of difficulty levels / sequence length limit */
#define LIMIT 4

/** Convenient numeric helpers */
#define ZERO 0
#define ONE 1

/**
 * ------------------------------
 * Timing and behavior tuning parameters (lower importance)
 * ------------------------------
 * These values control UI timing and can be tuned without changing
 * hardware pin assignments.
 */

/** 10 seconds in milliseconds */
#define SECOND_10 10000UL

/** 2 seconds in milliseconds */
#define SECOND_2 2000UL

/** Small project-specific constant used in various places (legacy name F) */
#define F 100

/** Debounce interval (ms) used by input debouncing logic */
#define DEBOUNCE_DELAY 50

/** Interval (ms) between LED fade updates */
#define FADE_INTERVAL 15

/** Initial brightness for the fade animation (0..255) */
#define FADE_INITIAL_BRIGHTNESS 0

/** Initial fade step applied to brightness on each update */
#define FADE_INITIAL_AMOUNT 5

#endif