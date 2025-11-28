#include "Motor.h"

/**
 * @brief Constructs a Motor object for servo control.
 * 
 * @param pin The digital pin number where the servo is connected
 */
Motor::Motor(const uint8_t pin) : pin(pin) {
}

/**
 * @brief Attaches the servo to the pin, enabling control.
 * 
 * This method activates the servo by attaching it to the specified pin,
 * allowing it to receive position commands.
 */
void Motor::on() {
    this->motor.attach(this->pin);
}

/**
 * @brief Detaches the servo from the pin, disabling control.
 * 
 * This method deactivates the servo, which can help save power when the servo
 * is not in use and prevent jittering.
 */
void Motor::off() {
    this->motor.detach();
}

/**
 * @brief Sets the servo to a specific angular position.
 * 
 * This method converts the angle to the appropriate pulse width and sends
 * the command to the servo. The angle is constrained between 0 and 180 degrees.
 * 
 * @param angle The desired angle (0-180 degrees)
 */
void Motor::setPosition(uint8_t angle) {
    if (angle > 180) {
        angle = 180;
    } else if (angle < 0) {
        angle = 0;
    }
    // 750 -> 0, 2250 -> 180
    // 750 + angle*(2250-750)/180
    // updated values: min is 544, max 2400 (see ServoTimer2 doc)
    float coeff = (2400.0 - 544.0) / 180;
    this->motor.write(544 + angle * coeff);
}

/**
 * @brief Destructor that ensures the servo is properly detached.
 * 
 * This destructor calls the off() method to detach the servo from the pin
 * when the Motor object is destroyed, preventing the servo from remaining
 * active and consuming power unnecessarily.
 */
Motor::~Motor() {
    this->off();
}
