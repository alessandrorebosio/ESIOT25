#pragma once

/**
 * @brief Abstract base class for system-level hardware operations.
 *
 * This interface provides a collection of system-level hardware operations
 * including button input, LED control, and temperature sensing.
 */
class HWSystem {
  public:
    /**
     * @brief Construct a new HWSystem object.
     */
    HWSystem() = default;

    /**
     * @brief Check if the system button is pressed.
     *
     * @return true If the button is currently pressed.
     * @return false If the button is not pressed.
     */
    virtual bool isPressed(void) = 0;

    /**
     * @brief Turn on the first LED.
     */
    virtual void turnOnLed1(void) = 0;

    /**
     * @brief Turn off the first LED.
     */
    virtual void turnOffLed1(void) = 0;

    /**
     * @brief Turn on the second LED.
     */
    virtual void turnOnLed2(void) = 0;

    /**
     * @brief Turn off the second LED.
     */
    virtual void turnOffLed2(void) = 0;

    /**
     * @brief Get the current temperature reading.
     *
     * @return float The current temperature in degrees Celsius.
     */
    virtual float temperature(void) = 0;

    /**
     * @brief Destroy the HWSystem object.
     */
    virtual ~HWSystem() = default;
};
