#ifndef CONFIG_H
#define CONFIG_H

/**
 * @file config.h
 * @brief Global pin and serial configuration for the firmware
 *
 * This file exposes configuration macros used across the application:
 * - BAUD: serial communication speed (Serial)
 * - BTN_PIN: button input pin
 * - ALARM_LED_PIN, ACTION_LED_PIN, ON_LED_PIN: status LEDs
 * - SERVO_PIN: servo control pin
 * - TEMP_PIN: temperature sensor pin
 * - RADAR_ECHO_PIN, RADAR_TRIG_PIN: ultrasonic radar pins
 */

#define BAUD 9600

#define BTN_PIN 2

#define ALARM_LED_PIN 3
#define ACTION_LED_PIN 4
#define ON_LED_PIN 5

#define SERVO_PIN 6

#define TEMP_PIN 7

#define RADAR_ECHO_PIN 9
#define RADAR_TRIG_PIN 10

#endif