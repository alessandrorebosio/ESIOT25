#pragma once

#include "tasks/states/gate/GateState.h"

namespace Gate {

/**
 * @brief State representing when the gate is moving to open position
 * 
 * This state controls the smooth opening movement of the gate with
 * position interpolation over time. Can be interrupted by disabling.
 */
class Opening final : public GateState {
  public:
    /**
     * @brief Initialize opening sequence timer
     */
    void onEnter(GateTask &task, HWGate &hw, const bool &enabled);

    /**
     * @brief No special cleanup needed when exiting Opening state
     */
    void onExit(GateTask &task, HWGate &hw, const bool &enabled);

    /**
     * @brief Update gate position and check for completion or interruption
     */
    void tick(GateTask &task, HWGate &hw, const bool &enabled);

    /**
     * @brief Destroy the Opening state object
     */
    ~Opening() = default;
};

} // namespace Gate
