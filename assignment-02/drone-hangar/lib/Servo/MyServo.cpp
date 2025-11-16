
#include <MyServo.h>
#include <Servo.h>

/**
 * @file MyServo.cpp
 * @brief Implementation of simple door-control helpers using a servo.
 *
 * This module uses the Arduino `Servo` library to control a servo
 * attached to a digital pin. The functions provided here are simple
 * blocking helpers intended for straightforward door open/close
 * operations in educational/example projects.
 */

#define PERIOD 15

/**
 * @brief Close the door by moving the servo to the closed angle.
 * @param pin Digital pin where the servo is attached.
 *
 * This wrapper calls the internal `move()` helper with the
 * predefined angle for the closed position. The operation is
 * blocking.
 */
void closeDoor(const uint8_t pin) { move(pin, -90); }

/**
 * @brief Open the door by moving the servo to the open angle.
 * @param pin Digital pin where the servo is attached.
 *
 * This wrapper calls the internal `move()` helper with the
 * predefined angle for the open position. The operation is
 * blocking.
 */
void openDoor(const uint8_t pin) { move(pin, 90); }

/**
 * @brief Internal helper that performs a blocking incremental move.
 * @param pin Digital pin where the servo is attached.
 * @param degree Number of incremental steps (signed). Positive values
 * move towards the open direction, negative towards closed.
 */
void move(const uint8_t pin, const int degree) {
    for (int i = 0; i < abs(degree); i++) { // TOFIX

        delay(PERIOD);
    }
}