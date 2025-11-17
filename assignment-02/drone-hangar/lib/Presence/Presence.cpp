#include "Presence.h"

/**
 * @file Presence.cpp
 * @brief Implementation of the Presence sensor that reads a digital pin.
 */

#define CALIBRATION_TIME 10000

/**
 * @brief Construct a new Presence object.
 * @param pin Digital input pin connected to the presence sensor.
 */
Presence::Presence(const uint8_t pin) { this->pin = pin; }

/**
 * @brief Configure the sensor pin and perform startup calibration.
 *
 * Sets the sensor pin mode to `INPUT` and waits for a short
 * calibration period to allow passive sensors (like PIR) to stabilise.
 * This function blocks for the calibration duration and should be called
 * once during application setup.
 */
void Presence::begin() {
    pinMode(this->pin, INPUT);
    delay(CALIBRATION_TIME);
}

/**
 * @brief Read the sensor pin to determine presence.
 * @return true when the sensor output is HIGH (presence detected), false
 * otherwise.
 */
bool Presence::isHere() { return digitalRead(this->pin); }