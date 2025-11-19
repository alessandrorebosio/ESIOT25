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
 * - SONAR_ECHO_PIN, SONAR_TRIG_PIN: ultrasonic sonar pins
 */

#define BAUD 9600

#define BTN_PIN 2

#define L3_LED 3
#define L2_LED 4
#define L1_LED 5

#define SERVO_PIN 6

#define TEMP_PIN A0

#define PIR_PIN 8

#define SONAR_ECHO_PIN 9 
#define SONAR_TRIG_PIN 10

#endif