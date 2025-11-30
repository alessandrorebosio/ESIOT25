#pragma once

namespace Flight {
class FlightTask;
}

class HWFlight;
class Context;

namespace Flight {

/**
 * @brief Abstract base class for all flight states in the state pattern
 * 
 * Defines the interface that all concrete flight states must implement
 * for the flight control state machine.
 */
class FlightState {
  public:
    /**
     * @brief Called when entering the state
     * @param task Reference to the FlightTask
     * @param hw Reference to flight hardware interface
     * @param ctx Reference to application context
     * @param enabled Flag indicating if the system is enabled
     */
    virtual void onEnter(FlightTask &task, HWFlight &hw, Context &ctx, const bool &enabled) = 0;

    /**
     * @brief Called when exiting the state
     * @param task Reference to the FlightTask
     * @param hw Reference to flight hardware interface
     * @param ctx Reference to application context
     * @param enabled Flag indicating if the system is enabled
     */
    virtual void onExit(FlightTask &task, HWFlight &hw, Context &ctx, const bool &enabled) = 0;

    /**
     * @brief Called on each state machine tick
     * @param task Reference to the FlightTask
     * @param hw Reference to flight hardware interface
     * @param ctx Reference to application context
     * @param enabled Flag indicating if the system is enabled
     */
    virtual void tick(FlightTask &task, HWFlight &hw, Context &ctx, const bool &enabled) = 0;

    /**
     * @brief Virtual destructor for proper polymorphism
     */
    virtual ~FlightState() = default;
};

} // namespace Flight
