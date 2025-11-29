#pragma once

#include "tasks/states/system/SystemState.h"

namespace System {

/**
 * @brief Pre-alarm system state - elevated temperature conditions
 * 
 * This state represents warning conditions with temperatures between TEMP1 and TEMP2.
 * Monitors for temperature escalation to alarm conditions or return to normal.
 */
class PreAlarm final : public SystemState {
  public:
    /**
     * @brief Initialize pre-alarm state with warnings
     */
    void onEnter(SystemTask &task, HWSystem &hw, Context &ctx);

    /**
     * @brief Clean up pre-alarm indicators
     */
    void onExit(SystemTask &task, HWSystem &hw, Context &ctx);

    /**
     * @brief Monitor temperature for escalation or improvement
     */
    void tick(SystemTask &task, HWSystem &hw, Context &ctx);

    /**
     * @brief Destroy the PreAlarm state object
     */
    ~PreAlarm() = default;
};

} // namespace System
