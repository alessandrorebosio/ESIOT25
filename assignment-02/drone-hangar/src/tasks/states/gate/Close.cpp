#include "tasks/states/gate/Close.h"
#include "tasks/states/gate/Opening.h"
#include "tasks/GateTask.h"

namespace Gate {

/**
 * @brief Turn off motor when entering Close state
 * 
 * Turns off the motor to save power when gate reaches fully closed position.
 */
void Close::onEnter(GateTask &task, HWGate &hw, const bool &enabled) {
    hw.motorOff();
}

/**
 * @brief Turn on motor when exiting Close state
 * 
 * Reactivates motor when leaving closed state to prepare for movement.
 */
void Close::onExit(GateTask &task, HWGate &hw, const bool &enabled) {
    hw.motorOn();
}

/**
 * @brief Check if gate should start opening when enabled
 * 
 * Transitions to Opening state when the enabled flag becomes true,
 * initiating the gate opening sequence.
 */
void Close::tick(GateTask &task, HWGate &hw, const bool &enabled) {
    if (enabled) {
        task.changeState(new Opening);
    }
}

} // namespace Gate
