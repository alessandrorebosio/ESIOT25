#ifndef MYSERVO_H
#define MYSERVO_H

#include <Arduino.h>

/**
 * @file MyServo.h
 * @brief High-level servo helpers for the drone hangar door.
 *
 * Provides two simple blocking operations to open and close a door
 * using a servo motor. Implementation relies on the Arduino `Servo`
 * library (see `MyServo.cpp`).
 */

/**
 * @brief Move the door to the "closed" position.
 * @param pin Digital pin number used to control the servo.
 *
 * This is a convenience wrapper that calls the internal movement
 * routine with the target angle for the closed position.
 * The function is blocking.
 */
void closeDoor(const uint8_t pin);

/**
 * @brief Move the door to the "open" position.
 * @param pin Digital pin number used to control the servo.
 *
 * This is a convenience wrapper that calls the internal movement
 * routine with the target angle for the open position.
 * The function is blocking.
 */
void openDoor(const uint8_t pin);

#endif