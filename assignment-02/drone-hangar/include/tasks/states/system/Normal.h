#pragma once

#include "tasks/states/system/SystemState.h"

namespace System {

/**
 * @brief Normal system state - safe temperature conditions
 *
 * This state represents normal operation with temperatures below TEMP1.
 * Allows flight operations and monitors for temperature increases.
 */
class Normal final : public SystemState {
  private:
    unsigned long timer;

  public:
    /**
     * @brief Initialize normal state with flight allowed
     */
    void onEnter(SystemTask &task, HWSystem &hw, Context &ctx);

    /**
     * @brief Block flight operations when leaving normal state
     */
    void onExit(SystemTask &task, HWSystem &hw, Context &ctx);

    /**
     * @brief Monitor temperature and transition to PreAlarm if conditions met
     */
    void tick(SystemTask &task, HWSystem &hw, Context &ctx);

    /**
     * @brief Destroy the Normal state object
     */
    ~Normal() = default;
};

} // namespace System
