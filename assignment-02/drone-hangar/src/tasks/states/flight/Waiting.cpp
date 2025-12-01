#include "tasks/FlightTask.h"

#include "tasks/states/flight/Idle.h"
#include "tasks/states/flight/Checking.h"
#include "tasks/states/flight/Waiting.h"

#include "parameters.h"

namespace Flight {

/**
 * @brief Handles entry actions for Waiting state
 * @param task Reference to the FlightTask
 * @param hw Reference to flight hardware interface
 * @param ctx Reference to application context
 * @param enabled Flag indicating if the system is enabled
 */
void Waiting::onEnter(FlightTask &task, HWFlight &hw, Context &ctx, const bool &enabled) {
    this->timer = millis();
}

/**
 * @brief Handles exit actions for Waiting state
 * @param task Reference to the FlightTask
 * @param hw Reference to flight hardware interface
 * @param ctx Reference to application context
 * @param enabled Flag indicating if the system is enabled
 */
void Waiting::onExit(FlightTask &task, HWFlight &hw, Context &ctx, const bool &enabled) {
    // No action needed when exiting Waiting state
}

/**
 * @brief Executes one tick of the Waiting state
 * @param task Reference to the FlightTask
 * @param hw Reference to flight hardware interface
 * @param ctx Reference to application context
 * @param enabled Flag indicating if the system is enabled
 */
void Waiting::tick(FlightTask &task, HWFlight &hw, Context &ctx, const bool &enabled) {
    if (millis() - this->timer <= T5) {
        if (hw.isDetected()) {
            task.changeState(new Checking);
            ctx.printLanding();
            ctx.doLanding();
            ctx.startBlink();
            ctx.openGate();
        }
    } else {
        task.changeState(new Idle);
    }
}

} // namespace Flight
