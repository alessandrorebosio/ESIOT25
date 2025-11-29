#include "tasks/states/blink/On.h"
#include "tasks/states/blink/Off.h"
#include "tasks/BlinkTask.h"

namespace Blink {

/**
 * @brief Turn on the LED when entering On state
 */
void On::onEnter(BlinkTask &task, HWBlink &hw, const bool &enabled) {
    hw.turnOn();
}

/**
 * @brief No cleanup needed when exiting On state
 */
void On::onExit(BlinkTask &task, HWBlink &hw, const bool &enabled) {
    // No action needed when exiting On state
}

/**
 * @brief Transition to Off state to continue blinking cycle
 * 
 * Immediately transitions to Off state to create the blinking effect.
 * This creates a state machine that cycles: On -> Off -> On -> Off...
 */
void On::tick(BlinkTask &task, HWBlink &hw, const bool &enabled) {
    task.changeState(new Off);
}

} // namespace Blink
