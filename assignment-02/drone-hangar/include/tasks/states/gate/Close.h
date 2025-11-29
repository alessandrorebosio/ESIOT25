#pragma once

#include "tasks/states/gate/GateState.h"

namespace Gate {

/**
 * @brief State representing when the gate is fully closed
 * 
 * This state maintains the gate in the closed position with motor turned off
 * for energy efficiency. Transitions to Opening state when enabled.
 */
class Close final : public GateState {
  public:
    /**
     * @brief Turn off motor when entering Close state
     */
    void onEnter(GateTask &task, HWGate &hw, const bool &enabled);

    /**
     * @brief Turn on motor when exiting Close state
     */
    void onExit(GateTask &task, HWGate &hw, const bool &enabled);

    /**
     * @brief Check if gate should start opening when enabled
     */
    void tick(GateTask &task, HWGate &hw, const bool &enabled);

    /**
     * @brief Destroy the Close state object
     */
    ~Close() = default;
};

} // namespace Gate
