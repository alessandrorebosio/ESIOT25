#include "tasks/SystemTask.h"

/**
 * @brief Construct a new System Task object
 * @param btn Reference to button
 * @param ctx Reference to application context
 * @param period System task execution period in milliseconds
 */
SystemTask::SystemTask(Hardware &hw, Context &ctx, int period) : hardware(hw), context(ctx) {
    Task::init(period);
    this->context.isAutomatic() ? this->hardware.printAutomatic() : this->hardware.printManual();
}

/**
 * @brief Execute one tick of the system state machine
 *
 * Delegates to the current state's tick method to handle state logic,
 * temperature monitoring, and potential transitions.
 */
void SystemTask::tick(void) {
    if (this->hardware.isPressed()) {
        if (this->context.isAutomatic()) {
            this->context.setManual();
            this->hardware.printManual();
        } else {
            this->context.setAutomatic();
            this->hardware.printAutomatic();
        }
    }
}
