#pragma once

#include "Task.h"
#include "core/Context.h"
#include "model/Hardware.h"

/**
 * @brief Valve control task for managing motorized valve position.
 *
 * This task executes periodically to monitor and adjust the valve position
 * based on system requirements and current operational mode (automatic/manual).
 * It interfaces with both hardware components and system context to provide
 * coordinated valve control.
 */
class ValveTask final : public Task {
  private:
    Hardware &hardware;
    Context &context;
    uint8_t lastPerc;
    int lastPotValue;

  public:
    /**
     * @brief Constructs a new ValveTask object.
     * @param hw Reference to the Hardware object for device access.
     * @param ctx Reference to the Context object for state management.
     * @param period Task execution period in milliseconds.
     */
    explicit ValveTask(Hardware &hw, Context &ctx, int period);

    /**
     * @brief Execute one iteration of the valve control task.
     * This method is called periodically based on the task's execution period.
     * It reads system state, processes control logic, and updates valve position.
     */
    void tick(void) override;

    /**
     * @brief Destroy the ValveTask object.
     * Default destructor - cleans up hardware and state objects to prevent memory leaks.
     * Stops the motor and releases any acquired resources.
     */
    ~ValveTask() = default;
};
