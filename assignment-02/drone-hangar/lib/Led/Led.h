#pragma once

#include <Arduino.h>

/**
 * @brief LED class for controlling a digital LED.
 *
 * This class provides a simple interface for controlling an LED connected to a digital pin.
 * It handles pin initialization and basic on/off operations.
 */
class Led final {
  private:
    uint8_t pin;

  public:
    /**
     * @brief Constructs a Led object and initializes the pin as OUTPUT.
     *
     * @param pin The digital pin number where the LED is connected
     */
    explicit Led(uint8_t pin);

    /**
     * @brief Turns the LED on.
     */
    void on();

    /**
     * @brief Turns the LED off.
     */
    void off();

    /**
     * @brief Default destructor.
     */
    ~Led() = default;
};
