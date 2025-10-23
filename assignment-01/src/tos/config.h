#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
/**
 * @file config.h
 * @brief Hardware configuration and constants for ToS (Test of Sequence)
 * 
 * This file contains all pin definitions, timing constants, and hardware
 * configuration parameters for the game system. Centralizes all hardware-
 * specific settings for easy maintenance and portability.
 */
#define BUTTON0 2
#define BUTTON1 3
#define BUTTON2 4
#define BUTTON3 5

#define LED0 6
#define LED1 7
#define LED2 8
#define LED3 9

#define LSLED_PIN 10

#define POTENTIOMETER_PIN A0

#define SECOND_10 10000UL
#define SECOND_2  2000UL

#define ANALOG_MAX_VALUE 1023
#define LIMIT 4
#define ONE 1

#define F 100

#define LEN(arr) (sizeof(arr) / sizeof((arr)[0]))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

static const int BUTTONS[] = {BUTTON0, BUTTON1, BUTTON2, BUTTON3};
static const int LEDS[]    = {LED0, LED1, LED2, LED3};

#define SEQ_LEN MIN(LEN(BUTTONS), LEN(LEDS))

#endif
