#include "tasks/states/gate/Opening.h"
#include "tasks/states/gate/Closing.h"
#include "tasks/states/gate/Open.h"
#include "tasks/GateTask.h"
#include "parameters.h"

static unsigned long timer;

namespace Gate {

/**
 * @brief Initialize opening sequence timer
 * 
 * Starts the timer to track the opening movement duration.
 */
void Opening::onEnter(GateTask &task, HWGate &hw, const bool &enabled) {
    timer = millis();
}

/**
 * @brief No special cleanup needed when exiting Opening state
 */
void Opening::onExit(GateTask &task, HWGate &hw, const bool &enabled) {
    // No action needed when exiting Opening state
}

/**
 * @brief Update gate position and check for completion or interruption
 * 
 * Calculates current gate position based on elapsed time and transitions
 * to Open state when fully open, or to Closing state if interrupted.
 */
void Opening::tick(GateTask &task, HWGate &hw, const bool &enabled) {
    // Check for interruption - transition to closing if disabled during opening
    if (!enabled) {
        task.changeState(new Closing);
    }

    // Calculate current position based on elapsed time
    unsigned long dt = millis() - timer;
    short pos = ((float)dt / OPEN_TIME) * OPEN_POS;

    // Set the calculated position
    hw.setPosition(pos);

    // Check if opening sequence is complete
    if (dt >= OPEN_TIME) {
        hw.setPosition(OPEN_POS);
        task.changeState(new Open);
    }
}

} // namespace Gate
