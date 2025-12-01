#pragma once

#include "Task.h"
#include "core/Context.h"
#include "model/api/HWSystem.h"
#include "tasks/states/system/SystemState.h"

namespace System {

/**
 * @brief Task for temperature monitoring system with state pattern
 *
 * This task manages temperature monitoring using a state machine with three states:
 * Normal, PreAlarm, and Alarm. It monitors temperature readings and controls
 * system behavior based on temperature thresholds and timing conditions.
 */
class SystemTask final : public Task {
  private:
    HWSystem *hardware;
    Context &context;
    SystemState *state;

  public:
    /**
     * @brief Construct a new System Task object
     * @param hw Pointer to hardware abstraction for system components
     * @param ctx Reference to application context
     * @param period System task execution period in milliseconds
     */
    explicit SystemTask(HWSystem *hw, Context &ctx, int period);

    /**
     * @brief Execute one tick of the system state machine
     *
     * Calls the current state's tick method to handle state transitions
     * and temperature monitoring logic.
     */
    void tick(void) override;

    /**
     * @brief Change the current state of the system state machine
     * @param newState Pointer to the new state to transition to
     *
     * Handles state transition by calling onExit for current state,
     * deleting it, then calling onEnter for the new state.
     */
    void changeState(SystemState *newState);

    /**
     * @brief Destroy the System Task object
     *
     * Cleans up hardware and state objects to prevent memory leaks.
     */
    ~SystemTask();
};

} // namespace System
