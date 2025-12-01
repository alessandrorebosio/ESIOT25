#pragma once

#include "model/Hardware.h"
#include "model/api/HWBlink.h"
#include "model/api/HWFlight.h"
#include "model/api/HWGate.h"
#include "model/api/HWSystem.h"

/**
 * @brief Factory namespace for creating hardware abstraction objects.
 *
 * This namespace provides factory functions that create implementations
 * of hardware abstraction interfaces, bridging between the concrete
 * Hardware class and the abstract hardware interfaces used by the
 * application logic.
 */
namespace HardwareFactory {

/**
 * @brief Create a HWBlink implementation.
 *
 * @param hw Reference to the concrete Hardware object.
 * @return HWBlink* Pointer to a new HWBlink implementation.
 */
HWBlink *createHWBlink(Hardware &hw);

/**
 * @brief Create a HWFlight implementation.
 *
 * @param hw Reference to the concrete Hardware object.
 * @return HWFlight* Pointer to a new HWFlight implementation.
 */
HWFlight *createHWFlight(Hardware &hw);

/**
 * @brief Create a HWGate implementation.
 *
 * @param hw Reference to the concrete Hardware object.
 * @return HWGate* Pointer to a new HWGate implementation.
 */
HWGate *createHWGate(Hardware &hw);

/**
 * @brief Create a HWSystem implementation.
 *
 * @param hw Reference to the concrete Hardware object.
 * @return HWSystem* Pointer to a new HWSystem implementation.
 */
HWSystem *createHWSystem(Hardware &hw);


/**
 * @brief Measure the distance using the provided hardware sensors.
 *
 * Performs a single distance measurement using the given Hardware instance
 * (e.g., ultrasonic, infrared or LIDAR sensor) and returns the value in metres.
 *
 * @param hw Reference to the Hardware object used to access the sensor.
 * @return float Measured distance in metres. A negative value indicates an error
 *               (for example: sensor failure, invalid reading or timeout).
 */
float measureDistance(Hardware &hw);

/**
 * @brief Measure the ambient temperature using the provided hardware interface.
 *
 * Obtains a single temperature measurement from the sensor accessible via the given
 * Hardware instance and returns the result in degrees Celsius.
 *
 * @param hw Reference to a Hardware object that provides access to the temperature sensor.
 *           The caller must ensure that hw is properly initialized and remains valid for
 *           the duration of the call.
 *
 * @return The measured temperature in degrees Celsius as a float.
 */
float measureTemperature(Hardware &hw);

} // namespace HardwareFactory
