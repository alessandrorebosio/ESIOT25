#include "tasks/SystemTask.h"

/**
 * @brief Construct a new System Task object
 * @param btn Reference to button
 * @param ctx Reference to application context
 * @param period System task execution period in milliseconds
 */
SystemTask::SystemTask(Button &btn, Context &ctx, int period) : button(btn), context(ctx) {
    Task::init(period);
}

/**
 * @brief Execute one tick of the system state machine
 *
 * Delegates to the current state's tick method to handle state logic,
 * temperature monitoring, and potential transitions.
 */
void SystemTask::tick(void) {
    this->button.sync();
    if (this->button.isPressed()) {
        if (this->context.isAutomatic()) {
            this->context.setManual();
        } else {
            this->context.setAutomatic();
        }
    }
}

/**
 * @brief Destroy the System Task object
 *
 * Cleans up allocated hardware and state objects to prevent memory leaks.
 */
SystemTask::~SystemTask() {
}
