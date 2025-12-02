#include "tasks/FlightTask.h"

#include "tasks/states/flight/Idle.h"
#include "tasks/states/flight/Checking.h"
#include "tasks/states/flight/Waiting.h"

#include "parameters.h"

namespace Flight {

/**
 * @brief Handles entry actions for Idle state
 * @param task Reference to the FlightTask
 * @param hw Reference to flight hardware interface
 * @param ctx Reference to application context
 * @param enabled Flag indicating if the system is enabled
 */
void Idle::onEnter(FlightTask &task, HWFlight &hw, Context &ctx, const bool &enabled) {
    // No action needed when exiting Idle state
}

/**
 * @brief Handles exit actions for Idle state
 * @param task Reference to the FlightTask
 * @param hw Reference to flight hardware interface
 * @param ctx Reference to application context
 * @param enabled Flag indicating if the system is enabled
 */
void Idle::onExit(FlightTask &task, HWFlight &hw, Context &ctx, const bool &enabled) {
    // No action needed when exiting Idle state
}

/**
 * @brief Executes one tick of the Idle state
 * @param task Reference to the FlightTask
 * @param hw Reference to flight hardware interface
 * @param ctx Reference to application context
 * @param enabled Flag indicating if the system is enabled
 */
void Idle::tick(FlightTask &task, HWFlight &hw, Context &ctx, const bool &enabled) {
    if (enabled) {
        if (ctx.isTakeOffMsg()) {
            if (hw.distance() <= D1) {
                task.changeState(new Checking);
                ctx.printTakeOff();
                ctx.doTakeOff();
                ctx.startBlink();
                ctx.openGate();
            }
        }

        if (ctx.isLandingMsg()) {
            task.changeState(new Waiting);
        }
    }
}

} // namespace Flight
