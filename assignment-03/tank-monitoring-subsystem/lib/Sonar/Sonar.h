#pragma once

#include <Arduino.h>

/**
 * @brief Ultrasonic distance sensor (HC-SR04) controller class.
 *
 * This class provides an interface for measuring distance using an ultrasonic sensor.
 * It supports temperature compensation for accurate distance calculations.
 */
class Sonar final {
  private:
    uint8_t trigPin;
    uint8_t echoPin;
    float temperature;
    long timeOut;

    /**
     * @brief Calculates the speed of sound based on current temperature.
     *
     * @return The speed of sound in meters per second
     */
    float getSoundSpeed();

  public:
    /**
     * @brief Constructs a Sonar object and initializes the pins.
     *
     * @param trigPin The trigger pin number
     * @param echoPin The echo pin number
     * @param maxTime The maximum time to wait for echo in microseconds
     */
    Sonar(uint8_t trigPin, uint8_t echoPin, unsigned long maxTime);

    /**
     * @brief Sets the temperature for sound speed compensation.
     *
     * @param temperature The temperature in degrees Celsius
     */
    void setTemperature(float temperature);

    /**
     * @brief Measures and returns the distance to the nearest object.
     *
     * @return Distance in centimeters, or NO_OBJ_DETECTED if no object is detected
     */
    float readDistance();
};
