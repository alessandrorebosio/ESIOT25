#pragma once

#include "tasks/states/gate/GateState.h"

namespace Gate {

/**
 * @brief State representing when the gate is moving to closed position
 * 
 * This state controls the smooth closing movement of the gate with
 * position interpolation over time. Can be interrupted by enabling.
 */
class Closing final : public GateState {
  public:
    /**
     * @brief Initialize closing sequence timer
     */
    void onEnter(GateTask &task, HWGate &hw, const bool &enabled);

    /**
     * @brief No special cleanup needed when exiting Closing state
     */
    void onExit(GateTask &task, HWGate &hw, const bool &enabled);

    /**
     * @brief Update gate position and check for completion or interruption
     */
    void tick(GateTask &task, HWGate &hw, const bool &enabled);

    /**
     * @brief Destroy the Closing state object
     */
    ~Closing() = default;
};

} // namespace Gate
