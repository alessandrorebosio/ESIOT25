#include "tasks/BlinkTask.h"
#include "tasks/states/blink/Off.h"

namespace Blink {

/**
 * @brief Construct a new Blink Task:: Blink Task object
 * @param hw Pointer to hardware abstraction for LED control
 * @param enabled Reference to enabled flag that controls blinking
 * @param period Blink task execution period in milliseconds
 */
BlinkTask::BlinkTask(HWBlink *hw, const bool &enabled, int period) 
    : hardware(hw), enabled(enabled), state(nullptr) {
    Task::init(period);
    this->changeState(new ::Blink::Off);
}

/**
 * @brief Execute one tick of the blink state machine
 * 
 * Delegates to the current state's tick method to handle state logic
 * and potential transitions.
 */
void BlinkTask::tick(void) {
    this->state->tick(*this, *this->hardware, this->enabled);
}

/**
 * @brief Change the current state of the blink state machine
 * @param newState Pointer to the new state to transition to
 * 
 * Manages the state transition lifecycle by calling onExit for current state,
 * deleting it, setting new state, and calling onEnter for the new state.
 */
void BlinkTask::changeState(BlinkState *newState) {
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
 * @brief Destroy the Blink Task object
 * 
 * Cleans up allocated hardware and state objects to prevent memory leaks.
 */
BlinkTask::~BlinkTask() {
    delete this->hardware;
    delete this->state;
}

} // namespace Blink
