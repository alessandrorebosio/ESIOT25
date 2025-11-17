#include <MyServo.h>

#define ROTATION 90
#define PERIOD 15

/**
 * @file MyServo.cpp
 * @brief Implementation of simple door-control helpers using a servo.
 *
 * This module uses the Arduino `Servo` library to control a servo
 * attached to a digital pin. The functions provided here are simple
 * blocking helpers intended for straightforward door open/close
 * operations in educational/example projects.
 */

/**
 * @brief Construct a MyServo instance bound to a pin.
 * @param pin Digital pin used for the servo signal.
 */
MyServo::MyServo(const uint8_t pin) { this->pin = pin; }

/**
 * @brief Attach the servo to the configured pin and enable control.
 */
void MyServo::on() { motor.attach(this->pin); }

/**
 * @brief Detach the servo and stop driving the pin.
 */
void MyServo::off() { motor.detach(); }

/**
 * @brief Close the door by moving the servo to the closed angle.
 *
 * This implementation performs a blocking, incremental movement from
 * the current position to the closed angle using small delays defined
 * by `PERIOD` to smooth motion.
 */
void MyServo::closeDoor() {
    for (int i = 0; i < ROTATION; i++) {
        motor.write(i);
        delay(PERIOD);
    }
}

/**
 * @brief Open the door by moving the servo to the open angle.
 *
 * This implementation performs a blocking, incremental movement from
 * the current position to the open angle using small delays defined
 * by `PERIOD` to smooth motion.
 */
void MyServo::openDoor() {
    for (int i = ROTATION; i > 0; i--) {
        motor.write(i);
        delay(PERIOD);
    }
}