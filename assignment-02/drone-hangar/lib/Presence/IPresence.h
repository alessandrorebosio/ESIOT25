#ifndef IPRESENCE_H
#define IPRESENCE_H

#include <Arduino.h>

/**
 * @file IPresence.h
 * @brief Interface for presence sensors (e.g., PIR or switch).
 *
 * This interface defines the minimal contract required for any presence
 * detector used in the drone-hangar project. Implementations should provide
 * a concrete `isHere()` method that returns true when presence is detected.
 */

/**
 * @brief Abstract interface for presence detection.
 *
 * Implementers must provide the `isHere` method which indicates whether
 * someone (or something) is present at the sensor location. This keeps
 * higher-level code decoupled from the specific sensor hardware.
 */
class IPresence {
  public:
    /**
     * @brief Initialize the presence sensor.
     *
     * Prepare the sensor hardware for operation. Implementations should
     * configure any required pins and perform any startup/calibration steps
     * necessary before `isHere()` may be called. This method should be
     * called once during setup.
     */
    virtual void begin() = 0;

    /**
     * @brief Check whether presence is detected.
     * @return true if presence is detected (sensor active), false otherwise.
     */
    virtual bool isHere() = 0;

    /**
     * @brief Virtual destructor for interface safety.
     *
     * Ensures derived classes are destructed correctly through base pointers.
     */
    virtual ~IPresence() = default;
};

#endif