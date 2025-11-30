#pragma once

#include "tasks/states/flight/FlightState.h"

namespace Flight {

/**
 * @brief Operating state for flight control system
 * 
 * Represents the active operational state where the system performs
 * takeoff or landing operations. Monitors for operation completion
 * to transition back to idle state.
 */
class Operating final : public FlightState {
  public:
    /**
     * @brief Called when entering the Operating state
     * @param task Reference to the FlightTask
     * @param hw Reference to flight hardware interface
     * @param ctx Reference to application context
     * @param enabled Flag indicating if the system is enabled
     */
    void onEnter(FlightTask &task, HWFlight &hw, Context &ctx, const bool &enabled);

    /**
     * @brief Called when exiting the Operating state
     * @param task Reference to the FlightTask
     * @param hw Reference to flight hardware interface
     * @param ctx Reference to application context
     * @param enabled Flag indicating if the system is enabled
     */
    void onExit(FlightTask &task, HWFlight &hw, Context &ctx, const bool &enabled);

    /**
     * @brief Executes one tick of the Operating state logic
     * @param task Reference to the FlightTask
     * @param hw Reference to flight hardware interface
     * @param ctx Reference to application context
     * @param enabled Flag indicating if the system is enabled
     */
    void tick(FlightTask &task, HWFlight &hw, Context &ctx, const bool &enabled);

    /**
     * @brief Default destructor
     */
    ~Operating() = default;
};

} // namespace Flight
