#include "tasks/states/system/PreAlarm.h"
#include "tasks/SystemTask.h"
#include "tasks/states/system/Alarm.h"
#include "tasks/states/system/Normal.h"
#include "parameters.h"

static unsigned long timer; 

namespace System {

/**
 * @brief Initialize pre-alarm state with warnings
 * 
 * Sets up pre-alarm mode with display warnings and starts monitoring timer.
 */
void PreAlarm::onEnter(SystemTask &task, HWSystem &hw, Context &ctx) {
    ctx.printPreAlarm();
    timer = millis();
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
    // Return to normal if temperature improves
    if (hw.temperature() <= TEMP1) {
        task.changeState(new Normal);
        return;
    }

    // Check for escalation to alarm conditions
    if (hw.temperature() >= TEMP2) {
        if (millis() - timer >= T2) {
            task.changeState(new Alarm);
        }
    } else {
        timer = millis();  // Reset timer if temperature drops below critical threshold
    }
}

} // namespace System
