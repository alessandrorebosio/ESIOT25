#pragma once

#include "Task.h"
#include "core/Context.h"

namespace Observer {

/**
 * @brief Function pointer type for observer callback functions
 *
 * Represents a void function with no parameters that will be called
 * when the observer condition is met.
 */
typedef void (*Function)(void);

/**
 * @brief Observer task that executes a function when a predicate condition is true
 *
 * This class monitors a predicate condition in the context and executes
 * a callback function when the condition evaluates to true. It inherits
 * from Task to provide periodic checking capability.
 */
class ObserverTask final : public Task {
  private:
    Predicate predicate;
    Function function;

  public:
    /**
     * @brief Construct a new Observer Task object
     * @param pred Pointer to predicate method that returns bool
     * @param fn Callback function to execute when predicate is true
     * @param period Execution period in milliseconds for checking the condition
     */
    explicit ObserverTask(Predicate pred, Function fn, int period);

    /**
     * @brief Check the predicate condition and execute callback if true
     *
     * This method is called periodically by the task scheduler. It evaluates
     * the predicate condition on the context and if it returns true,
     * executes the registered callback function.
     */
    void tick() override;

    /**
     * @brief Destroy the Observer Task object
     */
    ~ObserverTask() = default;
};

} // namespace Observer
