#pragma once

#include <Arduino.h>

/**
 * @brief Abstract base class for implementing periodic tasks
 *
 * This class provides the framework for creating tasks that need to run
 * at regular intervals. Derived classes must implement the tick() method
 * with the actual task logic.
 */
class Task {
  private:
    unsigned long periodUs;
    unsigned long lastRun;

  public:
    /**
     * @brief Initialize the task with specified period
     * @param periodMs Execution period in milliseconds
     *
     * Sets up the task to run periodically with the given time interval.
     * The period is stored internally in microseconds for higher precision.
     */
    void init(unsigned long periodMs) {
        this->periodUs = periodMs * 1000UL;
        this->lastRun = 0;
    }

    /**
     * @brief Check if the task should run based on elapsed time
     * @param currentTime Current time in microseconds
     * @return true if the task should run, false otherwise
     *
     * Compares the time elapsed since last execution against the task period.
     * If sufficient time has passed, updates lastRun time and returns true.
     */
    bool shouldRun(unsigned long currentTime) {
        if ((currentTime - lastRun) >= periodUs) {
            lastRun = currentTime;
            return true;
        }
        return false;
    }

    /**
     * @brief Pure virtual function to be implemented by derived classes
     *
     * Contains the actual task logic that will be executed periodically
     * when shouldRun() returns true.
     */
    virtual void tick(void) = 0;

    /**
     * @brief Virtual destructor for proper cleanup of derived classes
     */
    virtual ~Task() = default;
};
