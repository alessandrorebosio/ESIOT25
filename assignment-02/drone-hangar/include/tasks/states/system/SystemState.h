#pragma once

class HWSystem;
class Context;

namespace System {

class SystemTask;

/**
 * @brief Abstract base class for system states in the state pattern
 *
 * Defines the interface for all system states with lifecycle methods
 * for state transitions and periodic updates in the temperature monitoring system.
 */
class SystemState {
  public:
    /**
     * @brief Called when entering this state
     * @param task Reference to the SystemTask
     * @param hw Reference to the hardware abstraction
     * @param ctx Reference to the application context
     */
    virtual void onEnter(SystemTask &task, HWSystem &hw, Context &ctx) = 0;

    /**
     * @brief Called when exiting this state
     * @param task Reference to the SystemTask
     * @param hw Reference to the hardware abstraction
     * @param ctx Reference to the application context
     */
    virtual void onExit(SystemTask &task, HWSystem &hw, Context &ctx) = 0;

    /**
     * @brief Called periodically to update state logic
     * @param task Reference to the SystemTask
     * @param hw Reference to the hardware abstraction
     * @param ctx Reference to the application context
     *
     * Handles state-specific logic, temperature monitoring, and state transitions.
     */
    virtual void tick(SystemTask &task, HWSystem &hw, Context &ctx) = 0;

    /**
     * @brief Virtual destructor for proper cleanup of derived states
     */
    virtual ~SystemState() = default;
};

} // namespace System
