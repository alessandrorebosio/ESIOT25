#include "tasks/states/flight/Checking.h"
#include "tasks/FlightTask.h"
#include "tasks/states/flight/Idle.h"

#include "parameters.h"

namespace Flight {

/**
 * @brief Initializes timers when entering the Checking state.
 * 
 * Sets both takeOffTimer and landingTimer to the current system time.
 * This ensures fresh timing starts when the state becomes active.
 * 
 * @param task FlightTask instance managing the state machine.
 * @param hw Hardware interface for flight systems.
 * @param ctx Context containing flight state and control flags.
 * @param enabled Whether the state is currently enabled.
 */
void Checking::onEnter(FlightTask &task, HWFlight &hw, Context &ctx, const bool &enabled) {
    this->takeOffTimer = millis();
    this->landingTimer = millis();
}

/**
 * @brief Cleans up when exiting the Checking state.
 * 
 * Stops any ongoing LED blinking and closes the gate.
 * 
 * @param task FlightTask instance managing the state machine.
 * @param hw Hardware interface for flight systems.
 * @param ctx Context containing flight state and control flags.
 * @param enabled Whether the state is currently enabled.
 */
void Checking::onExit(FlightTask &task, HWFlight &hw, Context &ctx, const bool &enabled) {
    ctx.stopBlink();
    ctx.closeGate();
}

/**
 * @brief Periodic update function for the Checking state.
 * 
 * Checks for two possible conditions:
 * 1. Takeoff in progress: Verifies if distance >= D1 for at least T3 milliseconds.
 * 2. Landing in progress: Verifies if distance <= D1 for at least T4 milliseconds.
 * 
 * If either condition is met, transitions to Idle state and triggers appropriate
 * completion actions. If neither is in progress, also transitions to Idle.
 * 
 * @param task FlightTask instance for state transition.
 * @param hw Hardware interface for distance readings.
 * @param ctx Context containing takeoff/landing progress flags.
 * @param enabled Whether the state is currently enabled.
 */
void Checking::tick(FlightTask &task, HWFlight &hw, Context &ctx, const bool &enabled) {
    if (ctx.isTakeOffInProgress()) {
        if (hw.distance() >= D1) {
            if (millis() - this->takeOffTimer >= T3) {
                task.changeState(new Idle);
                ctx.printOutside();
                ctx.takeOffDone();
            }
        } else {
            this->takeOffTimer = millis();
        }
    }

    if (ctx.isLandingInProgress()) {
        if (hw.distance() <= D1) {
            if (millis() - this->landingTimer >= T4) {
                task.changeState(new Idle);
                ctx.printInside();
                ctx.landingDone();
            }
        } else {
            this->landingTimer = millis();
        }
    }

    if (!ctx.isTakeOffInProgress() && !ctx.isLandingInProgress()) {
        task.changeState(new Idle);
    }
}

} // namespace Flight
