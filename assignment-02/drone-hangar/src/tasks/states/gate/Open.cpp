#include "tasks/states/gate/Open.h"
#include "tasks/states/gate/Closing.h"
#include "tasks/GateTask.h"

namespace Gate {

/**
 * @brief Turn off motor when entering Open state
 * 
 * Turns off the motor to save power when gate reaches fully open position.
 */
void Open::onEnter(GateTask &task, HWGate &hw, const bool &enabled) {
    hw.motorOff();
}

/**
 * @brief Turn on motor when exiting Open state
 * 
 * Reactivates motor when leaving open state to prepare for movement.
 */
void Open::onExit(GateTask &task, HWGate &hw, const bool &enabled) {
    hw.motorOn();
}

/**
 * @brief Check if gate should start closing when disabled
 * 
 * Transitions to Closing state when the enabled flag becomes false,
 * initiating the gate closing sequence.
 */
void Open::tick(GateTask &task, HWGate &hw, const bool &enabled) {
    if (!enabled) {
        task.changeState(new Closing);
    }
}

} // namespace Gate
