#include "tasks/states/system/PreAlarm.h"
#include "tasks/SystemTask.h"
#include "tasks/states/system/Alarm.h"
#include "tasks/states/system/Normal.h"
#include "parameters.h"

namespace System {

/**
 * @brief Initialize pre-alarm state with warnings
 * 
 * Sets up pre-alarm mode with display warnings and starts monitoring timer.
 */
void PreAlarm::onEnter(SystemTask &task, HWSystem &hw, Context &ctx) {
    ctx.printPreAlarm();
    this->timer = millis();
}

/**
 * @brief Clean up pre-alarm indicators
 * 
 * Turns off LED indicators when leaving pre-alarm state.
 */
void PreAlarm::onExit(SystemTask &task, HWSystem &hw, Context &ctx) {
    hw.turnOffLed1();
}

/**
 * @brief Monitor temperature for escalation or improvement
 * 
 * Returns to Normal if temperature drops below TEMP1.
 * Escalates to Alarm if temperature reaches TEMP2 for T2 milliseconds continuously.
 * Resets timer if temperature drops below TEMP2.
 */
void PreAlarm::tick(SystemTask &task, HWSystem &hw, Context &ctx) {
    if (hw.temperature() <= TEMP1) {
        task.changeState(new Normal);
        return;
    }

    if (hw.temperature() >= TEMP2) {
        if (millis() - this->timer >= T2) {
            task.changeState(new Alarm);
        }
    } else {
        this->timer = millis();
    }
}

} // namespace System
