#pragma once

#include <Arduino.h>

/**
 * @class Potentiometer
 * @brief A class for interfacing with analog potentiometers.
 *
 * This class provides a simple interface to read values from an analog
 * potentiometer connected to an Arduino board. It handles pin initialization
 * and provides a method to read the current potentiometer value.
 *
 * @note This class is marked as final and cannot be inherited from.
 */
class Potentiometer final {
  private:
    uint8_t pin;

  public:
    /**
     * @brief Constructs a new Potentiometer object.
     *
     * Initializes the specified pin as an input for reading analog values.
     *
     * @param pin The analog pin number where the potentiometer is connected.
     *            Must be a valid analog pin (e.g., A0, A1, etc.).
     */
    explicit Potentiometer(uint8_t pin);

    /**
     * @brief Reads the current value from the potentiometer.
     *
     * Reads the analog voltage from the potentiometer and returns a value
     * between 0 and 1023 (for 10-bit ADC resolution on most Arduino boards).
     *
     * @return int The analog reading value (0-1023).
     */
    int read(void);

    /**
     * @brief Default destructor.
     */
    ~Potentiometer() = default;
};
