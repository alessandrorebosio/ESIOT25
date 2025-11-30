#include "tasks/ObserverTask.h"

/**
 * @brief Construct a new Observer Task:: Observer Task object
 * @param pred Pointer to predicate method that returns bool
 * @param fn Callback function to execute when predicate is true
 * @param period Execution period in milliseconds for checking the condition
 */
Observer::ObserverTask::ObserverTask(Predicate pred, Function fn, int period) 
    : predicate(pred), function(fn) {
    Task::init(period);
}

/**
 * @brief Check the predicate condition and execute callback if true
 * 
 * This method is called periodically by the task scheduler. It evaluates
 * the predicate condition on the context and if it returns true,
 * executes the registered callback function.
 */
void Observer::ObserverTask::tick(void) {
    if (this->predicate && this->function) {
        this->function();
    }
}
