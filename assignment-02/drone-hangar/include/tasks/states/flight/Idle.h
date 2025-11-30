#pragma once

#include "tasks/states/flight/FlightState.h"

namespace Flight {

/**
 * @brief Idle state for flight control system
 * 
 * Represents the system's idle state where it waits for takeoff or landing commands.
 * In this state, the system monitors for incoming messages and proximity sensors
 * to transition to appropriate operational states.
 */
class Idle final : public FlightState {
  public:
    /**
     * @brief Called when entering the Idle state
     * @param task Reference to the FlightTask
     * @param hw Reference to flight hardware interface
     * @param ctx Reference to application context
     * @param enabled Flag indicating if the system is enabled
     */
    void onEnter(FlightTask &task, HWFlight &hw, Context &ctx, const bool &enabled);

    /**
     * @brief Called when exiting the Idle state
     * @param task Reference to the FlightTask
     * @param hw Reference to flight hardware interface
     * @param ctx Reference to application context
     * @param enabled Flag indicating if the system is enabled
     */
    void onExit(FlightTask &task, HWFlight &hw, Context &ctx, const bool &enabled);

    /**
     * @brief Executes one tick of the Idle state logic
     * @param task Reference to the FlightTask
     * @param hw Reference to flight hardware interface
     * @param ctx Reference to application context
     * @param enabled Flag indicating if the system is enabled
     */
    void tick(FlightTask &task, HWFlight &hw, Context &ctx, const bool &enabled);

    /**
     * @brief Default destructor
     */
    ~Idle() = default;
};

} // namespace Flight
