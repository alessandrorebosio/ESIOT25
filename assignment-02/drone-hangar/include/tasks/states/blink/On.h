#pragma once

#include "tasks/states/blink/BlinkState.h"

namespace Blink {

/**
 * @brief State representing when the LED is turned on
 *
 * This state turns the LED on when entered and automatically transitions
 * to the Off state after one tick, creating the blinking effect.
 */
class On final : public BlinkState {
  public:
    /**
     * @brief Turn on the LED when entering this state
     */
    void onEnter(BlinkTask &task, HWBlink &hw, const bool &enabled);

    /**
     * @brief No action needed when exiting On state
     */
    void onExit(BlinkTask &task, HWBlink &hw, const bool &enabled);

    /**
     * @brief Transition to Off state to continue blinking cycle
     */
    void tick(BlinkTask &task, HWBlink &hw, const bool &enabled);

    /**
     * @brief Destroy the On state object
     */
    ~On() = default;
};

} // namespace Blink
