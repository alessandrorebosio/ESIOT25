#include "tasks/states/blink/Off.h"
#include "tasks/states/blink/On.h"
#include "tasks/BlinkTask.h"

namespace Blink {

/**
 * @brief Turn off the LED when entering Off state
 */
void Off::onEnter(BlinkTask &task, HWBlink &hw, const bool &enabled) {
    hw.turnOff();
}

/**
 * @brief No cleanup needed when exiting Off state
 */
void Off::onExit(BlinkTask &task, HWBlink &hw, const bool &enabled) {
    // No action needed when exiting Off state
}

/**
 * @brief Transition to On state if blinking is enabled
 * 
 * Only transitions to On state when the enabled flag is true,
 * allowing the blinking to be paused while maintaining the state machine.
 */
void Off::tick(BlinkTask &task, HWBlink &hw, const bool &enabled) {
    if (enabled) {
        task.changeState(new On);
    }
}

} // namespace Blink
