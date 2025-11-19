#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "ITemperature.h"

/**
 * @file Temperature.h
 * @brief TMP36-based analog temperature sensor reader.
 *
 * This class converts the analog input value from a TMP36 sensor
 * into a temperature expressed in Celsius.
 */

/**
 * @class Temperature
 * @brief Simple driver for the TMP36 temperature sensor.
 */
class Temperature : public ITemperature {
  private:
    uint8_t pin;

  public:
    /**
     * @brief Creates a Temperature reader bound to an analog pin.
     * @param pin Analog input pin (e.g., A0).
     */
    Temperature(uint8_t pin);

    /**
     * @brief Initializes the sensor pin as input.
     */
    void begin();

    /**
     * @brief Reads the current temperature in Celsius.
     * @return Temperature in °C.
     */
    float read();

    int equals(int value);
};

#endif
