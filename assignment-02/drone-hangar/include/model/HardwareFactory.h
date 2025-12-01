#pragma once

#include "model/Hardware.h"
#include "model/api/HWBlink.h"
#include "model/api/HWFlight.h"
#include "model/api/HWGate.h"
#include "model/api/HWOperating.h"
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
 * @brief Create a HWOperating implementation.
 *
 * @param hw Reference to the concrete Hardware object.
 * @return HWOperating* Pointer to a new HWOperating implementation.
 */
HWOperating *createHWOperating(Hardware &hw);

/**
 * @brief Create a HWSystem implementation.
 *
 * @param hw Reference to the concrete Hardware object.
 * @return HWSystem* Pointer to a new HWSystem implementation.
 */
HWSystem *createHWSystem(Hardware &hw);

} // namespace HardwareFactory
