#include "Timer.h"

/**
 * @file Timer.cpp
 * @brief Implementation of the `Timer` class using Arduino `millis()`.
 */

/**
 * @brief Return whether the timer is currently running.
 *
 * This returns the value of the internal `running` flag.
 */
bool Timer::is_running() { return this->running; }

/**
 * @brief Initialize the timer with a timeout in milliseconds.
 *
 * Records the current `millis()` value as the start time and sets the
 * internal running flag.
 */
void Timer::init(const unsigned long timeout_ms) {
    this->timeout = timeout_ms;
    this->start = millis();
    this->running = true;
}

/**
 * @brief Check whether the timer has expired.
 *
 * Returns false if the timer is not running. Otherwise compares the
 * elapsed milliseconds since `start` with the configured `timeout`.
 */
bool Timer::is_expired() {
    if (!this->running)
        return false;
    return (millis() - this->start) >= this->timeout;
}
