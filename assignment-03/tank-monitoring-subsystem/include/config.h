#pragma once

/**
 * @file config.h
 * @brief Hardware configuration for distance measurement system.
 *
 * This file contains pin assignments and constants specifically for
 * ultrasonic distance measurement and status indication components.
 */

/**
 * @brief Pin for the green status LED.
 *
 * Used to indicate normal operation or successful conditions.
 * Should be connected with appropriate current-limiting resistor.
 */
#define GREEN_LED 2

/**
 * @brief Pin for the red status LED.
 *
 * Used to indicate warnings, errors, or critical conditions.
 * Should be connected with appropriate current-limiting resistor.
 */
#define RED_LED 3

/**
 * @brief Echo pin for the ultrasonic distance sensor.
 *
 * Receives the echo pulse from the ultrasonic sensor.
 * This pin should be configured as INPUT.
 */
#define DIST_ECHO_PIN 4

/**
 * @brief Trigger pin for the ultrasonic distance sensor.
 *
 * Sends the trigger pulse to initiate distance measurement.
 * This pin should be configured as OUTPUT.
 */
#define DIST_TRIG_PIN 5

/**
 * @brief Maximum timeout for ultrasonic pulse measurement.
 *
 * Maximum time in microseconds to wait for the echo pulse.
 * This determines the maximum measurable distance.
 * Formula: distance = (timeout × speed of sound) / 2
 *
 * @note Setting this too high may cause long blocking waits.
 */
#define MAXTIME 5000

/**
 * WiFi SSID (leave empty and set at deploy time)
 */
#define WIFI_SSID ""

/**
 * WiFi password (leave empty and set at deploy time)
 */
#define WIFI_PASSWORD ""

/**
 * MQTT broker hostname
 */
#define MQTT_SERVER "broker.mqtt-dashboard.com"

/**
 * MQTT broker port
 */
#define MQTT_PORT 1883

/**
 * Backend topic base
 */
#define BACKEND_TOPIC "backend"

/**
 * Name/ID for this ESP device
 */
#define ESP_NAME "esp32"

/**
 * Default update frequency (ms)
 */
#define DEFAULT_UPDATE_FREQUENCY 5000
