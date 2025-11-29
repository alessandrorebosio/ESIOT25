#include "tasks/states/system/Alarm.h"
#include "tasks/states/system/Normal.h"
#include "tasks/SystemTask.h"
#include "parameters.h"

namespace System {

/**
 * @brief Activate alarm indicators and warnings
 * 
 * Turns on alarm LED and displays alarm message to user.
 */
void Alarm::onEnter(SystemTask &task, HWSystem &hw, Context &ctx) {
    hw.turnOnLed2();
    ctx.printAlarm();
}

/**
 * @brief Deactivate alarm indicators
 * 
 * Turns off alarm LED when leaving alarm state.
 */
void Alarm::onExit(SystemTask &task, HWSystem &hw, Context &ctx) {
    hw.turnOffLed2();
}

/**
 * @brief Monitor for user acknowledgment to reset alarm
 * 
 * Waits for user button press to acknowledge alarm and return to normal state.
 * Temperature must have returned to safe levels for this to be effective.
 */
void Alarm::tick(SystemTask &task, HWSystem &hw, Context &ctx) {
    if (hw.isPressed()) {
        task.changeState(new Normal);
    }
}

} // namespace System
