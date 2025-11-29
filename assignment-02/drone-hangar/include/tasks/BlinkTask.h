#pragma once

#include <Led.h>

#include "model/blink/HWBlink.h"
#include "tasks/states/blink/BlinkState.h"
#include "Task.h"

namespace Blink {

/**
 * @brief Task for controlling LED blinking behavior with state pattern
 * 
 * This task manages LED blinking using a state machine pattern with two states:
 * On and Off. It periodically checks and transitions between states based on
 * the enabled flag and state logic.
 */
class BlinkTask final : public Task {
  private:
    HWBlink *hardware;
    const bool &enabled;
    BlinkState *state;

  public:
    /**
     * @brief Construct a new Blink Task object
     * @param hw Pointer to hardware abstraction for LED control
     * @param enabled Reference to enabled flag that controls blinking
     * @param period Blink task execution period in milliseconds
     */
    explicit BlinkTask(HWBlink *hw, const bool &enabled, int period);

    /**
     * @brief Execute one tick of the blink state machine
     * 
     * Calls the current state's tick method to handle state transitions
     * and LED control logic.
     */
    void tick(void) override;

    /**
     * @brief Change the current state of the blink state machine
     * @param newState Pointer to the new state to transition to
     * 
     * Handles state transition by calling onExit for current state,
     * deleting it, then calling onEnter for the new state.
     */
    void changeState(BlinkState *newState);

    /**
     * @brief Destroy the Blink Task object
     * 
     * Cleans up hardware and state objects to prevent memory leaks.
     */
    ~BlinkTask();
};

} // namespace Blink
