#pragma once

#include "Task.h"
#include "core/Context.h"
#include "model/Hardware.h"

class SystemTask final : public Task {
  private:
    Hardware &hardware;
    Context &context;
    enum { AUTOMATIC, MANUAL, UNCONNECTED } state;

  public:
    /**
     * @brief Construct a new System Task object
     * @param btn Reference to button
     * @param ctx Reference to application context
     * @param period System task execution period in milliseconds
     */
    explicit SystemTask(Hardware &hw, Context &ctx, int period);

    /**
     * @brief Execute one tick of the system state machine
     *
     * Calls the current state's tick method to handle state transitions
     * and temperature monitoring logic.
     */
    void tick(void) override;

    /**
     * @brief Destroy the System Task object
     *
     * Cleans up hardware and state objects to prevent memory leaks.
     */
    ~SystemTask() = default;
};
