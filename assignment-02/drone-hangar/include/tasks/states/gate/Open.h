#pragma once

#include "tasks/states/gate/GateState.h"

namespace Gate {

/**
 * @brief State representing when the gate is fully open
 * 
 * This state maintains the gate in the open position with motor turned off
 * for energy efficiency. Transitions to Closing state when disabled.
 */
class Open final : public GateState {
  public:
    /**
     * @brief Turn off motor when entering Open state
     */
    void onEnter(GateTask &task, HWGate &hw, const bool &enabled);

    /**
     * @brief Turn on motor when exiting Open state
     */
    void onExit(GateTask &task, HWGate &hw, const bool &enabled);

    /**
     * @brief Check if gate should start closing when disabled
     */
    void tick(GateTask &task, HWGate &hw, const bool &enabled);

    /**
     * @brief Destroy the Open state object
     */
    ~Open() = default;
};

} // namespace Gate
