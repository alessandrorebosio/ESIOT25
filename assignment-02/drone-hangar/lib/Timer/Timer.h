#ifndef TIMER_H
#define TIMER_H

#include <Arduino.h>

#include "ITimer.h"
/**
 * @file Timer.h
 * @brief Concrete Timer implementation using Arduino `millis()`.
 *
 * This class implements the `ITimer` interface and provides a simple
 * non-blocking timer based on the Arduino `millis()` clock. It stores
 * a start timestamp and a timeout in milliseconds.
 */

/**
 * @brief Concrete timer using Arduino `millis()`.
 *
 * The Timer class implements the `ITimer` interface and provides
 * non-blocking timeout semantics using unsigned long millisecond values.
 */
class Timer : public ITimer {
  private:
    unsigned long timeout = 0;
    unsigned long start = 0;
    bool running = false;

  public:
    /**
     * @brief Return whether the timer is currently running.
     * @return true if running, false otherwise
     */
    bool is_running();

    /**
     * @brief Initialize the timer with the specified timeout.
     *
     * @param timeout_ms Timeout value in milliseconds.
     */
    void init(unsigned long timeout_ms);

    /**
     * @brief Check whether the timer has expired.
     * @return true if the timer is running and the timeout elapsed,
     *         false otherwise
     */
    bool is_expired();
};

#endif