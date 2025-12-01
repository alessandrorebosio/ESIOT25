#pragma once

#include "tasks/states/flight/FlightState.h"

namespace Flight {

/**
 * @class Checking
 * @brief State class for Checking flight parameters during takeoff and landing.
 *
 * This state is responsible for monitoring distance sensors during takeoff and landing
 * phases, ensuring that the flight system meets required distance thresholds for
 * specified time durations before transitioning back to the Idle state.
 *
 * The state tracks two separate timers:
 * - takeOffTimer: Measures time above distance threshold D1 during takeoff
 * - landingTimer: Measures time below distance threshold D1 during landing
 */
class Checking : public FlightState {
  private:
    unsigned long takeOffTimer;
    unsigned long landingTimer;

  public:
    /**
     * @brief Called when entering the Checking state.
     *
     * Initializes the takeoff and landing timers to the current system time.
     *
     * @param task Reference to the FlightTask managing state transitions.
     * @param hw Reference to hardware interface for distance measurements.
     * @param ctx Reference to the flight context for state and control flags.
     * @param enabled Boolean flag indicating if state operations are enabled.
     */
    void onEnter(FlightTask &task, HWFlight &hw, Context &ctx, const bool &enabled);

    /**
     * @brief Called when exiting the Checking state.
     *
     * Stops any active LED blinking and closes the gate if applicable.
     *
     * @param task Reference to the FlightTask managing state transitions.
     * @param hw Reference to hardware interface.
     * @param ctx Reference to the flight context.
     * @param enabled Boolean flag indicating if state operations are enabled.
     */
    void onExit(FlightTask &task, HWFlight &hw, Context &ctx, const bool &enabled);

    /**
     * @brief Performs periodic checks during the Checking state.
     *
     * Monitors distance sensors and timers for both takeoff and landing sequences.
     * Transitions to Idle state when:
     * - Takeoff: Distance >= D1 for at least T3 milliseconds
     * - Landing: Distance <= D1 for at least T4 milliseconds
     * - Neither takeoff nor landing is in progress
     *
     * @param task Reference to the FlightTask for state transition.
     * @param hw Reference to hardware interface for distance readings.
     * @param ctx Reference to the flight context for progress flags.
     * @param enabled Boolean flag indicating if state operations are enabled.
     */
    void tick(FlightTask &task, HWFlight &hw, Context &ctx, const bool &enabled);

    /**
     * @brief Default destructor
     */
    ~Checking() = default;
};

} // namespace Flight
