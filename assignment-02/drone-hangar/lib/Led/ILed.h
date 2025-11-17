
#ifndef ILED_H
#define ILED_H

#include <Arduino.h>

/**
 * @file ILed.h
 * @brief Interface for simple LED control.
 *
 * The `ILed` interface exposes basic operations to manipulate an LED
 * attached to a digital pin. Implementations are expected to manage
 * the pin number internally (for example via a constructor or setter)
 * and provide non-blocking or blocking behaviors as documented.
 */

class ILed {
  public:
    /**
     * @brief Initialize the LED hardware and internal state.
     *
     * Configure the digital pin used by the LED and prepare any timers or
     * internal state required by non-blocking behaviors such as `blinking()`.
     * Call this method once during system setup before using other methods.
     */
    virtual void begin() = 0;

    /**
     * @brief Turn the LED on (uses the implementation's configured pin).
     *
     * Implementations should drive the configured digital pin to the
     * appropriate active level (typically `HIGH`).
     */
    virtual void turnOn() = 0;

    /**
     * @brief Turn the LED off (uses the implementation's configured pin).
     *
     * Implementations should drive the configured digital pin to the
     * appropriate inactive level (typically `LOW`).
     */
    virtual void turnOff() = 0;

    /**
     * @brief Execute a blinking behavior using the implementation's timing.
     *
     * Implementations may provide either blocking or non-blocking blink
     * behaviors. Consult the concrete class documentation to know which
     * strategy is used. For the provided `Led` class the blinking method
     * is non-blocking and driven by `millis()`.
     */
    virtual void blinking() = 0;

    /**
     * @brief Virtual destructor for interface safety.
     */
    virtual ~ILed() = default;
};

#endif