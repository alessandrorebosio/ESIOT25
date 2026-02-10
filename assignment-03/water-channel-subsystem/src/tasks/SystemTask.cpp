#include "tasks/SystemTask.h"

/**
 * @brief Construct a new System Task object
 * @param btn Reference to button
 * @param ctx Reference to application context
 * @param period System task execution period in milliseconds
 */
SystemTask::SystemTask(Hardware &hw, Context &ctx, int period) : hardware(hw), context(ctx) {
    Task::init(period);
    this->transitionToUnconnected();
}

/**
 * @brief Execute one tick of the system state machine
 *
 * Delegates to the current state's tick method to handle state logic,
 * temperature monitoring, and potential transitions.
 */
void SystemTask::tick(void) {
    switch (state) {
        case AUTOMATIC:
            if (!this->context.isConnected()) {
                this->transitionToUnconnected();
            }

            if (this->hardware.isPressed() || this->context.consumeModeToggleRequest()) {
                this->transitionToManual();
            }
            break;
        case MANUAL:
            if (this->hardware.isPressed() || this->context.consumeModeToggleRequest()) {
                this->transitionToAutomatic();
            }
            break;
        case UNCONNECTED:
            if (this->context.isConnected()) {
                this->transitionToAutomatic();
            }
            break;
    }
}

/**
 * @brief Transition to automatic mode
 *
 * Updates the context response, prints automatic mode status to hardware,
 * sets the system to automatic mode, and updates the internal state.
 */
void SystemTask::transitionToAutomatic() {
    this->context.setResponse("AUTOMATIC");
    this->hardware.printAutomatic();
    this->context.setAutomatic();
    this->state = AUTOMATIC;
}

/**
 * @brief Transition to manual mode
 *
 * Updates the context response, prints manual mode status to hardware,
 * sets the system to manual mode, and updates the internal state.
 */
void SystemTask::transitionToManual() {
    this->context.setResponse("MANUAL");
    this->hardware.printManual();
    this->context.setManual();
    this->state = MANUAL;
}

/**
 * @brief Transition to unconnected mode
 *
 * Updates the context response, prints unconnected status to hardware,
 * sets the system to manual mode (safe fallback), and updates the internal state.
 */
void SystemTask::transitionToUnconnected() {
    this->context.setResponse("UNCONNECTED");
    this->hardware.printUnconnected();
    this->context.setManual();
    this->state = UNCONNECTED;
}
