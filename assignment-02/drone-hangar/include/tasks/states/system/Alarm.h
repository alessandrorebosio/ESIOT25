#pragma once

#include "tasks/states/system/SystemState.h"

namespace System {

/**
 * @brief Alarm system state - critical temperature conditions
 * 
 * This state represents critical temperature conditions requiring immediate attention.
 * Activated when temperature remains above TEMP2 for T2 milliseconds.
 */
class Alarm final : public SystemState {
  public:
    /**
     * @brief Activate alarm indicators and warnings
     */
    void onEnter(SystemTask &task, HWSystem &hw, Context &ctx);

    /**
     * @brief Deactivate alarm indicators
     */
    void onExit(SystemTask &task, HWSystem &hw, Context &ctx);

    /**
     * @brief Monitor for user acknowledgment to reset alarm
     */
    void tick(SystemTask &task, HWSystem &hw, Context &ctx);

    /**
     * @brief Destroy the Alarm state object
     */
    ~Alarm() = default;
};

} // namespace System
