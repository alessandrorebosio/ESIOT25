#include "tasks/GateTask.h"
#include "tasks/states/gate/Close.h"

namespace Gate {

/**
 * @brief Construct a new Gate Task:: Gate Task object
 * @param hw Pointer to hardware abstraction for gate control
 * @param enabled Reference to enabled flag that controls gate operation
 * @param period Gate task execution period in milliseconds
 */
GateTask::GateTask(HWGate *hw, const bool &enabled, int period) : hardware(hw), enabled(enabled), state(nullptr) {
    Task::init(period);
    this->changeState(new ::Gate::Close);
}

/**
 * @brief Execute one tick of the gate state machine
 *
 * Delegates to the current state's tick method to handle state logic,
 * position control, and potential transitions.
 */
void GateTask::tick(void) {
    this->state->tick(*this, *this->hardware, this->enabled);
}

/**
 * @brief Change the current state of the gate state machine
 * @param newState Pointer to the new state to transition to
 *
 * Manages the state transition lifecycle by calling onExit for current state,
 * deleting it, setting new state, and calling onEnter for the new state.
 */
void GateTask::changeState(GateState *newState) {
    if (this->state != nullptr) {
        this->state->onExit(*this, *this->hardware, this->enabled);
        delete this->state;
    }
    this->state = newState;
    if (this->state != nullptr) {
        this->state->onEnter(*this, *this->hardware, this->enabled);
    }
}

/**
 * @brief Destroy the Gate Task object
 *
 * Cleans up allocated hardware and state objects to prevent memory leaks.
 */
GateTask::~GateTask() {
    delete this->state;
}

} // namespace Gate
