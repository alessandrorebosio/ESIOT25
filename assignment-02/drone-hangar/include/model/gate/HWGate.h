#pragma once

#include <Motor.h>

/**
 * @brief Hardware abstraction layer for gate motor control
 * 
 * Provides a simplified interface for controlling a gate motor
 * with position control capabilities.
 */
class HWGate final {
  private:
    Motor &motor;

  public:
    /**
     * @brief Construct a new HWGate object
     * @param motor Reference to motor instance
     */
    explicit HWGate(Motor &motor);

    /**
     * @brief Turn on the motor (enable power)
     */
    void motorOn(void);

    /**
     * @brief Turn off the motor (disable power)
     */
    void motorOff(void);

    /**
     * @brief Set the gate position
     * @param angle Target position angle in degrees
     */
    void setPosition(short angle);

    /**
     * @brief Destroy the HWGate object
     */
    ~HWGate() = default;
};
