#pragma once

namespace Blink {
class BlinkTask;
}

class HWBlink;

namespace Blink {

/**
 * @brief Abstract base class for blink states in the state pattern
 * 
 * Defines the interface for all blink states with lifecycle methods
 * for state transitions and periodic updates.
 */
class BlinkState {
  public:
    /**
     * @brief Called when entering this state
     * @param task Reference to the BlinkTask
     * @param hw Reference to the hardware abstraction
     * @param enabled Reference to the enabled flag
     */
    virtual void onEnter(BlinkTask &task, HWBlink &hw, const bool &enabled) = 0;

    /**
     * @brief Called when exiting this state
     * @param task Reference to the BlinkTask
     * @param hw Reference to the hardware abstraction
     * @param enabled Reference to the enabled flag
     */
    virtual void onExit(BlinkTask &task, HWBlink &hw, const bool &enabled) = 0;

    /**
     * @brief Called periodically to update state logic
     * @param task Reference to the BlinkTask
     * @param hw Reference to the hardware abstraction
     * @param enabled Reference to the enabled flag
     * 
     * Handles state-specific logic and potential state transitions.
     */
    virtual void tick(BlinkTask &task, HWBlink &hw, const bool &enabled) = 0;

    /**
     * @brief Virtual destructor for proper cleanup of derived states
     */
    virtual ~BlinkState() = default;
};

} // namespace Blink
