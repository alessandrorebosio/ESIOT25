#pragma once

#include "core/Context.h"
#include "model/flight/HWFlight.h"
#include "tasks/states/flight/FlightState.h"
#include "Task.h"

namespace Flight {

/**
 * @brief Flight control task implementing a state machine pattern
 * 
 * Manages flight operations through a state machine with three main states:
 * - Idle: System waiting for commands
 * - Operating: Active takeoff or landing operations
 * - Waiting: Temporary state for landing detection
 * 
 * The task coordinates hardware interactions and state transitions
 * based on sensor data and external commands.
 */
class FlightTask final : public Task {
  private:
    HWFlight *hardware;
    Context &context;
    const bool &enabled;
    FlightState *state;

    /**
     * @brief Determines the initial state based on system conditions
     * @return FlightState* Pointer to the initial state object
     * 
     * Checks if operation is already done to decide between Idle or Operating state.
     * This ensures the system starts in the correct state after initialization.
     */
    FlightState *initialState(void);

  public:
    /**
     * @brief Constructs a new Flight Task object
     * @param hw Pointer to flight hardware abstraction
     * @param ctx Reference to application context
     * @param enabled Reference to system enabled flag
     * @param period Task execution period in milliseconds
     * 
     * Initializes the state machine with the appropriate starting state
     * based on current system conditions.
     */
    explicit FlightTask(HWFlight *hw, Context &ctx, const bool &enabled, int period);

    /**
     * @brief Executes one iteration of the flight state machine
     * 
     * Delegates to the current state's tick method to handle
     * state-specific logic and potential state transitions.
     */
    void tick() override;

    /**
     * @brief Transitions to a new state in the state machine
     * @param newState Pointer to the new state object
     * 
     * Performs proper state transition sequence:
     * 1. Calls onExit() for current state
     * 2. Deletes current state object
     * 3. Sets new state
     * 4. Calls onEnter() for new state
     */
    void changeState(FlightState *newState);

    /**
     * @brief Destroys the Flight Task object
     * 
     * Cleans up allocated hardware and state objects
     * to prevent memory leaks.
     */
    ~FlightTask();
};

} // namespace Flight
