#include <Arduino.h>

#include "timer.h"

/**
 * Start or restart a timer.
 *
 * This sets the timer start timestamp from `millis()` and sets the timeout
 * duration in milliseconds. The timer is marked as running.
 *
 * @param t Pointer to a Timer structure. If NULL the function does nothing.
 * @param timeout_ms Timeout duration in milliseconds.
 */
void timerInit(Timer *t, unsigned long timeout_ms) {
    if (!t)
        return;
    t->timeout = timeout_ms;
    t->start = millis();
    t->running = true;
}

/**
 * Check if a timer has expired.
 *
 * - If `t` is NULL the function returns true (treat as expired).
 * - If the timer is not running the function returns false.
 * - Uses unsigned arithmetic (`now - t->start`) so wrap-around of
 *   `millis()` is handled correctly.
 *
 * @param t Pointer to the Timer to check.
 * @return true if the timer has expired, false otherwise.
 */
bool timer_expired(const Timer *t) {
    if (!t)
        return true;
    if (!t->running)
        return false;
    unsigned long now = millis();
    return (now - t->start) >= t->timeout;
}