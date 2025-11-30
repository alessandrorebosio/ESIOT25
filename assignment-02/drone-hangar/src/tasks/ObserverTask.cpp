#include "tasks/ObserverTask.h"

/**
 * @brief Construct a new Observer Task:: Observer Task object
 * @param enabled Reference to boolean condition that enables the callback
 * @param fn Callback function to execute when condition is true
 * @param period Execution period in milliseconds for checking the condition
 */
Observer::ObserverTask::ObserverTask(const bool &enabled, Function fn, int period) : enabled(enabled), function(fn) {
    Task::init(period);
}

/**
 * @brief Check the condition and execute callback if true
 *
 * This method is called periodically by the task scheduler. It evaluates
 * the enabled condition and if it returns true, executes the registered
 * callback function.
 */
void Observer::ObserverTask::tick(void) {
    if (this->enabled && this->function) {
        this->function();
    }
}
