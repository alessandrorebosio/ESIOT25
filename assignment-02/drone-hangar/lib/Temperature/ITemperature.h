#ifndef ITEMPERATURE_H
#define ITEMPERATURE_H

#include <Arduino.h>

/**
 * @file ITemperature.h
 * @brief Interface for temperature sensor drivers.
 *
 * This interface defines the methods required to read a temperature value
 * in Celsius from any supported temperature sensor implementation.
 */

/**
 * @class ITemperature
 * @brief Abstract interface for temperature readers.
 */
class ITemperature {
public:
    /**
     * @brief Initializes the temperature sensor.
     */
    virtual void begin() = 0;

    /**
     * @brief Reads the current temperature value.
     * @return Temperature in Celsius.
     */
    virtual float read() = 0;

    virtual int equals(int value) = 0;

    /**
     * @brief Virtual destructor for safe polymorphic deletion.
     */
    virtual ~ITemperature() = default;
};

#endif
