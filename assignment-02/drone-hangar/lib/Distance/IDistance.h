#ifndef IDISTANCE_H
#define IDISTANCE_H

#include <Arduino.h>

/**
 * @file IDistance.h
 * @brief Interface for distance sensor drivers.
 *
 * Provides the minimal API required to initialize the sensor and
 * read a distance measurement in centimeters.
 */
class IDistance {
public:
    /**
     * @brief Initializes the distance sensor.
     */
    virtual void begin() = 0;

    /**
     * @brief Reads the detected distance.
     * @return Distance in centimeters, or a negative value if no object is detected.
     */
    virtual float read() = 0;

    /**
     * @brief Virtual destructor for safe polymorphic usage.
     */
    virtual ~IDistance() = default;
};

#endif
