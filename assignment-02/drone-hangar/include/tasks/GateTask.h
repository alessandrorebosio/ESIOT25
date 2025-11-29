#pragma once

#include <Motor.h>

#include "model/gate/HWGate.h"
#include "tasks/states/gate/GateState.h"
#include "Task.h"

namespace Gate {

/**
 * @brief Task for controlling gate operation with state pattern
 * 
 * This task manages gate movement using a state machine with four states:
 * Open, Close, Opening, and Closing. It handles smooth gate movement
 * with position control and enables/disables motor as needed.
 */
class GateTask final : public Task {
  private:
    HWGate *hardware;
    const bool &enabled;
    GateState *state;

  public:
    /**
     * @brief Construct a new Gate Task object
     * @param hw Pointer to hardware abstraction for gate control
     * @param enabled Reference to enabled flag that controls gate operation
     * @param period Gate task execution period in milliseconds
     */
    explicit GateTask(HWGate *hw, const bool &enabled, int period);

    /**
     * @brief Execute one tick of the gate state machine
     * 
     * Calls the current state's tick method to handle state transitions
     * and gate position control logic.
     */
    void tick(void) override;

    /**
     * @brief Change the current state of the gate state machine
     * @param newState Pointer to the new state to transition to
     * 
     * Handles state transition by calling onExit for current state,
     * deleting it, then calling onEnter for the new state.
     */
    void changeState(GateState *newState);

    /**
     * @brief Destroy the Gate Task object
     * 
     * Cleans up hardware and state objects to prevent memory leaks.
     */
    ~GateTask();
};

} // namespace Gate
