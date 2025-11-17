#ifndef IMYSERVO_H
#define IMYSERVO_H

#include <Arduino.h>

/**
 * @file IMyServo.h
 * @brief Interface for a simple servo-based door controller.
 *
 * The `IMyServo` interface exposes basic operations to manage a servo
 * used for opening and closing a door. Implementations may choose to
 * perform blocking or non-blocking motions; consult the concrete class
 * documentation for details.
 */

class IMyServo {
  public:
    /**
     * @brief Attach/enable the servo motor (power/attach to pin).
     */
    virtual void on() = 0;

    /**
     * @brief Detach/disable the servo motor (stop driving the pin).
     */
    virtual void off() = 0;

    /**
     * @brief Move the servo to the open position.
     *
     * The semantics (blocking vs non-blocking) depend on the
     * implementation.
     */
    virtual void openDoor() = 0;

    /**
     * @brief Move the servo to the closed position.
     */
    virtual void closeDoor() = 0;

    /**
     * @brief Virtual destructor for interface safety.
     */
    virtual ~IMyServo() = default;
};

#endif