#pragma once

#include <Button.h>
#include <Led.h>
#include <TMP36.h>

/**
 * @brief Hardware abstraction layer for system components
 * 
 * Provides a unified interface to access button, LED, and temperature sensor
 * hardware components with simplified method calls.
 */
class HWSystem final {
  private:
    Button &button;
    Led &led1;
    Led &led2;
    TMP36 &temp;

  public:
    /**
     * @brief Construct a new HWSystem object
     * @param btn Reference to button instance
     * @param led1 Reference to first LED instance
     * @param led2 Reference to second LED instance
     * @param temp Reference to temperature sensor instance
     */
    explicit HWSystem(Button &btn, Led &led1, Led &led2, TMP36 &temp);

    /**
     * @brief Check if button is pressed
     * @return true if button is pressed, false otherwise
     */
    bool isPressed(void);

    /**
     * @brief Turn on the first LED (normal/pre-alarm indicator)
     */
    void turnOnLed1(void);

    /**
     * @brief Turn off the first LED
     */
    void turnOffLed1(void);

    /**
     * @brief Turn on the second LED (alarm indicator)
     */
    void turnOnLed2(void);

    /**
     * @brief Turn off the second LED
     */
    void turnOffLed2(void);

    /**
     * @brief Read current temperature from sensor
     * @return float Current temperature in degrees Celsius
     */
    float temperature(void);

    /**
     * @brief Destroy the HWSystem object
     */
    ~HWSystem() = default;
};
