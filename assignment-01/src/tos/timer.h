#ifndef TIMER_H
#define TIMER_H

#include <stdbool.h>

/**
 * @file timer.h
 * @brief Simple non-blocking timer helpers for millis()-based environments.
 *
 * The timers are lightweight wrappers around an unsigned long start time and a
 * timeout value (in milliseconds). They are intended for use in environments
 * like Arduino where `millis()` returns an unsigned long tick count.
 *
 * Note about wrap-around: this API follows the common Arduino pattern where
 * the subtraction of two unsigned long values correctly handles timer
 * wrap-around.
 */

/**
 * @brief Millisecond-resolution stopwatch-style timer.
 *
 * The Timer struct records when a timer was started, how long it should
 * run (timeout), and whether it is currently active. It is suitable for
 * lightweight timeout checks in environments with a millisecond tick source.
 *
 * Fields:
 *  - start: Tick (milliseconds) when the timer was started. Typically read
 *           from the platform's millisecond clock.
 *  - timeout: Duration in milliseconds after which the timer is considered
 *             expired. A timer is expired when (now - start) >= timeout.
 *  - running: True if the timer has been started and is currently active;
 *             false if the timer is stopped or inactive.
 */
typedef struct {
    /**
     * Tick (millis) when the timer was started.
     */
    unsigned long start;
    /**
     * Timeout duration in milliseconds.
     */
    unsigned long timeout;
    /**
     * Whether the timer is currently running.
     */
    bool running;
} Timer;

/**
 * @brief Determine whether a Timer is currently running.
 *
 * Returns true if the Timer pointed to by t is active (i.e., counting),
 * false if the Timer is stopped or has expired. If `t` is NULL the
 * function returns false.
 *
 * Note: the API uses pointer parameters to allow nullable semantics and to
 * remain compatible with C-style code. If you prefer non-nullable C++-only
 * usage, consider changing the signature to `bool is_running(const Timer &t)`.
 *
 * @param t Pointer to the Timer to check. May be NULL.
 * @return true if the timer is running, false otherwise.
 */
bool is_running(const Timer *t);

/**
 * Initialize and start a timer.
 *
 * This sets the timer start to the current value returned by `millis()` and
 * marks it as running.
 *
 * @param t Pointer to a Timer structure to initialize. If NULL the function
 *          does nothing.
 * @param timeout_ms Timeout duration in milliseconds.
 */
void timerInit(Timer *t, unsigned long timeout_ms);

/**
 * Check whether the timer has expired.
 *
 * The function returns true if the timer pointer is NULL (treated as
 * expired). If the timer is not running the function returns false.
 *
 * @param t Pointer to the Timer to check (may be NULL).
 * @return true if the timer has expired, false otherwise.
 */
bool timer_expired(const Timer *t);

#endif