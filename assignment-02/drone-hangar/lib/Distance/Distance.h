#ifndef DISTANCE_H
#define DISTANCE_H

#include "IDistance.h"

/**
 * @file Distance.h
 * @brief Sonar-based distance measurement using trigger/echo pins.
 *
 * This class implements distance reading using a typical HC-SR04 ultrasonic
 * sensor or compatible devices. Results are returned in centimeters.
 */

/**
 * @class Distance
 * @brief Driver for ultrasonic distance sensors.
 */
class Distance : public IDistance {
private:
    uint8_t trigPin;
    uint8_t echoPin;

public:
    /**
     * @brief Creates a distance reader using the specified trigger and echo pins.
     * @param trigPin Output pin used to generate the ultrasonic pulse.
     * @param echoPin Input pin used to measure the echo duration.
     */
    Distance(uint8_t trigPin, uint8_t echoPin);

    /**
     * @brief Configures the pins for the sonar sensor.
     */
    void begin();

    /**
     * @brief Measures the distance using the sonar.
     * @return Distance in centimeters, or NO_OBJECTS if no echo is detected.
     */
    float read();

    int equals(int value);
};

#endif
