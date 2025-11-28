#pragma once

#include <Arduino.h>

/**
 * @brief TMP36 analog temperature sensor controller class.
 * 
 * This class provides an interface for reading temperature from a TMP36 sensor.
 * It handles analog pin initialization and temperature conversion with averaging.
 */
class TMP36 final {
  private:
    uint8_t pin;

  public:
    /**
     * @brief Constructs a TMP36 object and initializes the pin as INPUT.
     * 
     * @param pin The analog pin number where the TMP36 sensor is connected
     */
    explicit TMP36(uint8_t pin);

    /**
     * @brief Reads the current temperature in Celsius.
     * 
     * This method takes multiple samples, averages them, and converts the
     * analog reading to temperature in degrees Celsius.
     * 
     * @return The temperature in degrees Celsius
     */
    float readTemperature();

    /**
     * @brief Default destructor.
     */
    ~TMP36() = default;
};
