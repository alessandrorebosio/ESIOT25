#include "Presence.h"

/**
 * @file Presence.cpp
 * @brief Implementation of the Presence sensor that reads a digital pin.
 */

/**
 * @brief Construct a new Presence object.
 * @param pin Digital input pin connected to the presence sensor.
 */
Presence::Presence(const uint8_t pin) { this->pin = pin; }

/**
 * @brief Read the sensor pin to determine presence.
 * @return true when the sensor output is HIGH (presence detected), false
 * otherwise.
 */
bool Presence::isHere() { return digitalRead(this->pin); }