#include "tasks/states/gate/Closing.h"
#include "tasks/states/gate/Close.h"
#include "tasks/states/gate/Opening.h"
#include "tasks/GateTask.h"
#include "parameters.h"

static unsigned long timer;

namespace Gate {

/**
 * @brief Initialize closing sequence timer
 * 
 * Starts the timer to track the closing movement duration.
 */
void Closing::onEnter(GateTask &task, HWGate &hw, const bool &enabled) {
    timer = millis();
}

/**
 * @brief No special cleanup needed when exiting Closing state
 */
void Closing::onExit(GateTask &task, HWGate &hw, const bool &enabled) {
    // No action needed when exiting Closing state
}

/**
 * @brief Update gate position and check for completion or interruption
 * 
 * Calculates current gate position based on elapsed time and transitions
 * to Close state when fully closed, or to Opening state if interrupted.
 */
void Closing::tick(GateTask &task, HWGate &hw, const bool &enabled) {
    // Check for interruption - transition to opening if enabled during closing
    if (enabled) {
        task.changeState(new Opening);
    }

    // Calculate current position based on elapsed time
    unsigned long dt = millis() - timer;
    short pos = OPEN_POS - ((float)dt / CLOSE_TIME) * OPEN_POS;

    // Set the calculated position
    hw.setPosition(pos);

    // Check if closing sequence is complete
    if (dt >= CLOSE_TIME) {
        hw.setPosition(CLOSE_POS);
        task.changeState(new Close);
    }
}

} // namespace Gate
