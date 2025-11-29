#pragma once

#include <Led.h>

/**
 * @brief Hardware abstraction layer for blinking LED
 * 
 * Provides a simplified interface for controlling an LED
 * for blinking purposes.
 */
class HWBlink final {
  private:
    Led &led;

  public:
    /**
     * @brief Construct a new HWBlink object
     * @param led Reference to LED instance
     */
    explicit HWBlink(Led &led);

    /**
     * @brief Turn on the LED
     */
    void turnOn(void);

    /**
     * @brief Turn off the LED
     */
    void turnOff(void);

    /**
     * @brief Destroy the HWBlink object
     */
    ~HWBlink() = default;
};
