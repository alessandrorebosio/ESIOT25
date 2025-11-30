#include "tasks/states/system/Normal.h"
#include "tasks/SystemTask.h"
#include "tasks/states/system/PreAlarm.h"
#include "parameters.h"

namespace System {

/**
 * @brief Initialize normal state with flight allowed
 * 
 * Sets up normal operation mode with LED indication and enables flight operations.
 */
void Normal::onEnter(SystemTask &task, HWSystem &hw, Context &ctx) {
    ctx.printNormal();
    hw.turnOnLed1();
    ctx.allowFlight();
    this->timer = millis();
}

/**
 * @brief Block flight operations when leaving normal state
 * 
 * Disables flight operations when transitioning out of normal state for safety.
 */
void Normal::onExit(SystemTask &task, HWSystem &hw, Context &ctx) {
    ctx.blockFlight();
}

/**
 * @brief Monitor temperature and transition to PreAlarm if conditions met
 * 
 * Checks if temperature remains above TEMP1 for T1 milliseconds continuously.
 * Resets timer if temperature drops below threshold.
 */
void Normal::tick(SystemTask &task, HWSystem &hw, Context &ctx) {
    if (hw.temperature() >= TEMP1) {
        if (millis() - this->timer >= T1) {
            task.changeState(new PreAlarm);
        }
    } else {
        this->timer = millis();
    }
}

} // namespace System
