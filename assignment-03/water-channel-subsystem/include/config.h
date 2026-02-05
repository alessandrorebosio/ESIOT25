#pragma once

/**
 * @file config.h
 * @brief Hardware configuration and pin assignments for the main system.
 *
 * This file contains all the hardware pin definitions and configuration
 * constants used throughout the project. Centralizing these definitions
 * makes it easier to manage hardware changes.
 */

/**
 * @brief Serial communication baud rate
 * @details Baud rate for serial communication in bits per second
 */
#define BAUD 9600

/**
 * @brief Analog pin connected to the potentiometer.
 *
 * Used to read analog values from a potentiometer for control input.
 */
#define POT_PIN A0

/**
 * @brief PWM pin connected to the servo motor.
 *
 * Used to control the position of a servo motor via PWM signals.
 * Must be a PWM-capable pin on the Arduino board.
 */
#define SERVO_PIN 2

/**
 * @brief Digital input pin for the push button.
 *
 * Used to detect button presses for user interaction.
 * Should be connected with a pull-up or pull-down resistor as appropriate.
 */
#define BUTTON_PIN 3

/**
 * @brief I2C address of the LCD display.
 *
 * The 7-bit I2C address of the LCD display module.
 * Common addresses are 0x27 or 0x3F for most LCD I2C backpack modules.
 */
#define LCD_ADDR 0x27

/**
 * @brief Number of columns in the LCD display.
 *
 * Defines the width of the LCD display in characters.
 * Standard LCD sizes are 16, 20, or 40 columns.
 */
#define LCD_COLS 16

/**
 * @brief Number of rows in the LCD display.
 *
 * Defines the height of the LCD display in characters.
 * Common LCD sizes are 1, 2, or 4 rows.
 */
#define LCD_ROWS 2
