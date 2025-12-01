#include "tasks/FlightTask.h"

#include "tasks/states/flight/Measuring.h"
#include "tasks/states/flight/Operating.h"

#include "parameters.h"

namespace Flight {

/**
 * @brief Handles entry actions for Operating state
 * @param task Reference to the FlightTask
 * @param hw Reference to flight hardware interface
 * @param ctx Reference to application context
 * @param enabled Flag indicating if the system is enabled
 */
void Operating::onEnter(FlightTask &task, HWFlight &hw, Context &ctx, const bool &enabled) {
    ctx.startBlink();
    ctx.openGate();
}

/**
 * @brief Handles exit actions for Operating state
 * @param task Reference to the FlightTask
 * @param hw Reference to flight hardware interface
 * @param ctx Reference to application context
 * @param enabled Flag indicating if the system is enabled
 */
void Operating::onExit(FlightTask &task, HWFlight &hw, Context &ctx, const bool &enabled) {
}

/**
 * @brief Executes one tick of the Operating state
 * @param task Reference to the FlightTask
 * @param hw Reference to flight hardware interface
 * @param ctx Reference to application context
 * @param enabled Flag indicating if the system is enabled
 */
void Operating::tick(FlightTask &task, HWFlight &hw, Context &ctx, const bool &enabled) {
    if (ctx.isOperationDone()) {
        task.changeState(new Measuring);
    }
}

} // namespace Flight
