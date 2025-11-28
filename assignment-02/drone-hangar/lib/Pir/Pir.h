#pragma once

#include <Arduino.h>

/**
 * @brief PIR (Passive Infrared) motion sensor controller class.
 * 
 * This class provides an interface for reading motion detection from a PIR sensor
 * and includes calibration functionality for stable operation.
 */
class Pir final {
  private:
    uint8_t pin;

  public:
    /**
     * @brief Constructs a Pir object and initializes the pin as INPUT.
     * 
     * @param pin The digital pin number where the PIR sensor is connected
     */
    explicit Pir(uint8_t pin);

    /**
     * @brief Checks if motion is detected by the PIR sensor.
     * 
     * @return true if motion is detected, false otherwise
     */
    bool isDetected();

    /**
     * @brief Calibrates the PIR sensor for stable operation.
     * 
     * This method should be called during setup to allow the sensor to stabilize
     * and establish a baseline reading. It includes a delay for calibration.
     */
    void calibrate();

    /**
     * @brief Default destructor.
     */
    ~Pir() = default;
};
