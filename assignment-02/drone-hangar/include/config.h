#pragma once

/**
 * @file config.h
 * @brief Hardware pin configuration and settings
 * 
 * This file contains all the hardware-specific configurations including
 * pin assignments, communication settings, and device addresses.
 */

/* Communication Settings */

/**
 * @brief Serial communication baud rate
 * @details Baud rate for serial communication in bits per second
 */
#define BAUD 9600

/* Pin Assignments */

/**
 * @brief Analog pin for temperature sensor (TMP36)
 */
#define TMP_PIN A0

/**
 * @brief Digital pin for button input
 */
#define BTN_PIN 2

/**
 * @brief Digital pin for LED 3
 */
#define L3_PIN 3

/**
 * @brief Digital pin for LED 2
 */
#define L2_PIN 4

/**
 * @brief Digital pin for LED 1
 */
#define L1_PIN 5

/**
 * @brief Digital pin for servo motor control
 */
#define SERVO_PIN 6

/**
 * @brief Digital pin for PIR motion sensor
 */
#define PIR_PIN 8

/**
 * @brief Digital pin for ultrasonic sensor echo
 */
#define SNR_ECHO_PIN 9

/**
 * @brief Digital pin for ultrasonic sensor trigger
 */
#define SNR_TRIG_PIN 10

/* LCD Display Configuration */

/**
 * @brief I2C address of the LCD display
 */
#define LCD_ADDR 0x27

/**
 * @brief Number of columns in the LCD display
 */
#define LCD_COLS 16

/**
 * @brief Number of rows in the LCD display
 */
#define LCD_ROWS 2

/* Sensor Settings */

/**
 * @brief Maximum time for ultrasonic sensor measurement
 * @details Time in microseconds for sonar sensor timeout
 */
#define MAXTIME 5000
