
#ifndef ITIMER_H
#define ITIMER_H

#include <Arduino.h>

/**
 * @file ITimer.h
 * @brief Abstract timer interface for non-blocking timeouts.
 *
 * This header declares the `ITimer` interface used by components that
 * require a simple, non-blocking timer. Implementations should provide
 * methods to initialize the timer and to query running/expired state
 * without blocking the main application loop.
 */
class ITimer {

  public:
    /**
     * @brief Return whether the timer is currently running.
     *
     * @return true if running, false otherwise
     */
    virtual bool is_running() = 0;

    /**
     * @brief Start the timer with a timeout in milliseconds.
     *
     * @param timeout_ms Timeout value in milliseconds.
     */
    virtual void init(unsigned long timeout_ms) = 0;

    /**
     * @brief Check whether the timer has expired.
     *
     * @return true if the timer is running and the timeout elapsed,
     *         false otherwise
     */
    virtual bool is_expired() = 0;

    /**
     * @brief Virtual destructor for interface safety.
     */
    virtual ~ITimer() = default;
};

#endif