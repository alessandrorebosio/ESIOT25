#ifndef LED_H
#define LED_H

#include "ILed.h"

/**
 * @file Led.h
 * @brief Concrete LED control implementation header.
 *
 * The `Led` class implements `ILed` and controls a single LED connected
 * to a digital pin. The pin number is stored in the `pin` member and
 * should be configured by the user (for example via a constructor or a
 * setter — not provided here). The provided `Led` implementation uses
 * a non-blocking `blinking()` implementation based on `millis()`.
 */

/**
 * @brief Concrete LED implementation using a configured digital pin.
 */
class Led : public ILed {
  private:
    uint8_t pin;

  public:
    /**
     * @brief Construct a Led instance bound to a pin.
     * @param pin Digital pin used for the led signal.
     */
    Led(uint8_t pin);

    /**
     * @brief Turn the LED on using the configured pin.
     */
    void turnOn();

    /**
     * @brief Turn the LED off using the configured pin.
     */
    void turnOff();

    /**
     * @brief Toggle the LED state periodically (non-blocking).
     *
     * The blink period is defined in `Led.cpp` by the `PERIOD` macro.
     * This implementation is non-blocking and relies on `millis()`.
     */
    void blinking();
};

#endif