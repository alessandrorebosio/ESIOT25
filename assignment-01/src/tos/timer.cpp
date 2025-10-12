#include "timer.h"

void timerInit(Timer *t, unsigned long timeout_ms) {
    if (!t)
        return;
    t->timeout = timeout_ms;
    t->start = millis();
    t->running = true;
}

bool timer_expired(const Timer *t) {
    if (!t)
        return true;
    if (!t->running)
        return false;
    unsigned long now = millis();
    return (now - t->start) >= t->timeout;
}

/*
 * Implementation notes:
 * - Uses `millis()` to obtain the current tick count. This keeps the API
 *   non-blocking and suitable for typical Arduino-style event loops.
 * - The subtraction `now - t->start` is performed using unsigned arithmetic
 *   so the result is correct even when `millis()` wraps around.
 */