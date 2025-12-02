#pragma once

/**
 * @brief Abstract base class for gate control hardware.
 *
 * This interface provides methods to control a gate mechanism,
 * typically involving motor control for opening, closing, and
 * positioning the gate.
 */
class HWGate {
  public:
    /**
     * @brief Turn the gate motor on.
     */
    virtual void motorOn(void) = 0;

    /**
     * @brief Turn the gate motor off.
     */
    virtual void motorOff(void) = 0;

    /**
     * @brief Set the gate to a specific position.
     *
     * @param angle The target angle or position for the gate.
     */
    virtual void setPosition(short angle) = 0;

    /**
     * @brief Destroy the HWGate object.
     */
    virtual ~HWGate() = default;
};
