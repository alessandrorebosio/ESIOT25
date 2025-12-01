#include "tasks/SystemTask.h"
#include "tasks/states/system/Normal.h"

namespace System {

/**
 * @brief Construct a new System Task:: System Task object
 * @param hw Pointer to hardware abstraction for system components
 * @param ctx Reference to application context
 * @param period System task execution period in milliseconds
 */
SystemTask::SystemTask(HWSystem *hw, Context &ctx, int period) : hardware(hw), context(ctx), state(nullptr) {
    Task::init(period);
    this->changeState(new ::System::Normal);
}

/**
 * @brief Execute one tick of the system state machine
 *
 * Delegates to the current state's tick method to handle state logic,
 * temperature monitoring, and potential transitions.
 */
void SystemTask::tick(void) {
    this->state->tick(*this, *this->hardware, this->context);
}

/**
 * @brief Change the current state of the system state machine
 * @param newState Pointer to the new state to transition to
 *
 * Manages the state transition lifecycle by calling onExit for current state,
 * deleting it, setting new state, and calling onEnter for the new state.
 */
void SystemTask::changeState(SystemState *newState) {
    if (this->state != nullptr) {
        this->state->onExit(*this, *this->hardware, this->context);
        delete this->state;
    }
    this->state = newState;
    if (this->state != nullptr) {
        this->state->onEnter(*this, *this->hardware, this->context);
    }
}

/**
 * @brief Destroy the System Task object
 *
 * Cleans up allocated hardware and state objects to prevent memory leaks.
 */
SystemTask::~SystemTask() {
    delete this->state;
}

} // namespace System
