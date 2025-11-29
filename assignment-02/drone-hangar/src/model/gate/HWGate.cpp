#include "model/gate/HWGate.h"

/**
 * @brief Construct a new HWGate object
 * @param motor Reference to motor instance
 */
HWGate::HWGate(Motor &motor) : motor(motor) {
}

/**
 * @brief Turn on the motor (enable power)
 */
void HWGate::motorOn(void) {
    this->motor.on();
}

/**
 * @brief Turn off the motor (disable power)
 */
void HWGate::motorOff(void) {
    this->motor.off();
}

/**
 * @brief Set the gate position
 * @param angle Target position angle in degrees
 */
void HWGate::setPosition(short angle) {
    this->motor.setPosition(angle);
}
