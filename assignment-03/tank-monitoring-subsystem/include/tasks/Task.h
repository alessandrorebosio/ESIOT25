#pragma once

/**
 * @brief Abstract base class for all tasks in the system.
 *
 * Provides a common interface for tasks. All specific task implementations
 * should inherit from this class. The destructor is virtual to ensure
 * proper cleanup of derived classes.
 */
class Task {
  public:
    /**
     * @brief Virtual destructor to allow proper polymorphic deletion.
     */
    virtual ~Task() = default;
};
