#include "tasks/SystemTask.h"

#define TIMEOUT_MS 5000

/**
 * @brief Construct a new System Task object
 * @param btn Reference to button
 * @param ctx Reference to application context
 * @param period System task execution period in milliseconds
 */
SystemTask::SystemTask(Hardware &hw, Context &ctx, int period) : hardware(hw), context(ctx) {
    Task::init(period);
    this->transitionToAutomatic();
}

/**
 * @brief Execute one tick of the system state machine
 *
 * Delegates to the current state's tick method to handle state logic,
 * temperature monitoring, and potential transitions.
 */
void SystemTask::tick(void) {
    bool isNetworkOk = (millis() - this->context.getLastMsgTime() < TIMEOUT_MS);

    switch (state) {
        case AUTOMATIC:
            if (!isNetworkOk) {
                this->transitionToUnconnected();
            }

            if (this->hardware.isPressed() || this->context.needChange()) {
                this->transitionToManual();
            }
            break;
        case MANUAL:
            if (this->hardware.isPressed() || this->context.needChange()) {
                this->transitionToAutomatic();
            }
            break;
        case UNCONNECTED:
            if (isNetworkOk) {
                this->transitionToAutomatic();
            }
            break;
    }
}

void SystemTask::transitionToAutomatic() {
    this->context.setResponse("AUTOMATIC");
    this->hardware.printAutomatic();
    this->context.setAutomatic();
    this->state = AUTOMATIC;
}

void SystemTask::transitionToManual() {
    this->context.setResponse("MANUAL");
    this->hardware.printManual();
    this->context.setManual();
    this->state = MANUAL;
}

void SystemTask::transitionToUnconnected() {
    this->context.setResponse("UNCONNECTED");
    this->hardware.printUnconnected();
    this->context.setManual();
    this->state = UNCONNECTED;
}
