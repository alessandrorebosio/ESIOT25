#pragma once

#include "tasks/states/blink/BlinkState.h"

namespace Blink {

/**
 * @brief State representing when the LED is turned off
 * 
 * This state turns the LED off when entered and transitions to On state
 * only if blinking is enabled, allowing for blinking to be toggled.
 */
class Off final : public BlinkState {
  public:
    /**
     * @brief Turn off the LED when entering this state
     */
    void onEnter(BlinkTask &task, HWBlink &hw, const bool &enabled);

    /**
     * @brief No action needed when exiting Off state
     */
    void onExit(BlinkTask &task, HWBlink &hw, const bool &enabled);

    /**
     * @brief Transition to On state if blinking is enabled
     */
    void tick(BlinkTask &task, HWBlink &hw, const bool &enabled);

    /**
     * @brief Destroy the Off state object
     */
    ~Off() = default;
};

} // namespace Blink
