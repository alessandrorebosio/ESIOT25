#pragma once

/**
 * @brief Abstract base class for hardware that can blink or toggle.
 *
 * This interface provides methods to turn hardware components on and off,
 * typically used for LEDs or other binary output devices.
 */
class HWBlink {
  public:
    /**
     * @brief Turn the hardware component on.
     */
    virtual void turnOn(void) = 0;

    /**
     * @brief Turn the hardware component off.
     */
    virtual void turnOff(void) = 0;

    /**
     * @brief Destroy the HWBlink object.
     */
    virtual ~HWBlink() = default;
};
