#ifndef CONFIG_H
#define CONFIG_H

/**
 * @file config.h
 * @brief Global pin and serial configuration for the firmware
 *
 * This header defines project-wide configuration macros used by the firmware:
 * - `BAUD`: Serial communication baud rate.
 * - `TEMP_PIN`: Analog input pin connected to the temperature sensor.
 * - `BTN_PIN`: Digital input pin connected to a push button.
 * - `L1_LED`, `L2_LED`, `L3_LED`: Status LEDs (three board LEDs).
 * - `SERVO_PIN`: PWM pin used to control the servo motor.
 * - `PIR_PIN`: Digital input pin for the PIR presence sensor.
 * - `SONAR_TRIG_PIN`, `SONAR_ECHO_PIN`: Pins used by the ultrasonic distance
 * sensor (trigger / echo).
 * - `D1`, `D2`: Application-specific numeric parameters.
 * - `T1`..`T4`: Time-related constants (milliseconds).
 * - `TEMP1`, `TEMP2`: Temperature thresholds or calibration values.
 *
 * Adjust these macros to match your hardware wiring and desired thresholds.
 */

#define BAUD 9600

#define TEMP_PIN A0
#define BTN_PIN 2
#define L3_LED 3
#define L2_LED 4
#define L1_LED 5
#define SERVO_PIN 6
#define PIR_PIN 7
#define SONAR_ECHO_PIN 8
#define SONAR_TRIG_PIN 9

#define D1 15
#define D2 15
#define T1 10000
#define T2 10000
#define T3 10000
#define T4 10000
#define TEMP1 50
#define TEMP2 50

#endif