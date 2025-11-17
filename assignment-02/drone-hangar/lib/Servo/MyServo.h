#ifndef MYSERVO_H
#define MYSERVO_H

#include <Servo.h>

#include "IMyServo.h"
/**
 * @file MyServo.h
 * @brief Servo-based door controller declaration.
 *
 * `MyServo` implements `IMyServo` using the Arduino `Servo` library
 * to move a servo between open and closed positions. The provided
 * implementation is blocking and uses small delays between incremental
 * position changes for smooth movement.
 */

/**
 * @brief Concrete servo controller for a door mechanism.
 */
class MyServo : public IMyServo {
  private:
    Servo motor;
    uint8_t pin;

  public:
    /**
     * @brief Construct a MyServo instance bound to a pin.
     * @param pin Digital pin used for the servo signal.
     */
    MyServo(uint8_t pin);

    /**
     * @brief Attach and enable the servo motor.
     */
    void on();

    /**
     * @brief Detach and disable the servo motor.
     */
    virtual void off();

    /**
     * @brief Move the servo to the open position (blocking).
     */
    void openDoor();

    /**
     * @brief Move the servo to the closed position (blocking).
     */
    void closeDoor();
};

#endif