#pragma once

#include "tasks/states/flight/FlightState.h"

namespace Flight {

/**
 * @brief Waiting state for flight control system
 *
 * Represents a temporary waiting state where the system waits for
 * detection signals within a specified timeout period. Used during
 * landing procedures to detect successful landing completion.
 */
class Waiting final : public FlightState {
  private:
    unsigned long timer;

  public:
    /**
     * @brief Called when entering the Waiting state
     * @param task Reference to the FlightTask
     * @param hw Reference to flight hardware interface
     * @param ctx Reference to application context
     * @param enabled Flag indicating if the system is enabled
     */
    void onEnter(FlightTask &task, HWFlight &hw, Context &ctx, const bool &enabled);

    /**
     * @brief Called when exiting the Waiting state
     * @param task Reference to the FlightTask
     * @param hw Reference to flight hardware interface
     * @param ctx Reference to application context
     * @param enabled Flag indicating if the system is enabled
     */
    void onExit(FlightTask &task, HWFlight &hw, Context &ctx, const bool &enabled);

    /**
     * @brief Executes one tick of the Waiting state logic
     * @param task Reference to the FlightTask
     * @param hw Reference to flight hardware interface
     * @param ctx Reference to application context
     * @param enabled Flag indicating if the system is enabled
     */
    void tick(FlightTask &task, HWFlight &hw, Context &ctx, const bool &enabled);

    /**
     * @brief Default destructor
     */
    ~Waiting() = default;
};

} // namespace Flight
