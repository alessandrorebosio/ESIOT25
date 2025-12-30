#pragma once

#include "Task.h"
#include "core/Context.h"

/**
 * @brief Function pointer type for observer callback functions
 *
 * Represents a void function with no parameters that will be called
 * when the observer condition is met.
 */
typedef void (*Function)(void);

/**
 * @brief Observer task that executes a function when a condition is true
 *
 * This class monitors a boolean condition and executes a callback function 
 * when the condition evaluates to true. It inherits from Task to provide 
 * periodic checking capability.
 */
class ObserverTask final : public Task {
  private:
    const bool &enabled;
    Function function;

  public:
    /**
     * @brief Construct a new Observer Task object
     * @param enabled Reference to boolean condition that enables the callback
     * @param fn Callback function to execute when condition is true
     * @param period Execution period in milliseconds for checking the condition
     */
    explicit ObserverTask(const bool &enabled, Function fn, int period);

    /**
     * @brief Check the condition and execute callback if true
     *
     * This method is called periodically by the task scheduler. It evaluates
     * the enabled condition and if it returns true, executes the registered 
     * callback function.
     */
    void tick() override;

    /**
     * @brief Destroy the Observer Task object
     */
    ~ObserverTask() = default;
};
