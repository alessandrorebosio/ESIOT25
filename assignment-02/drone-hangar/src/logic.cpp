#include "logic.h"

/**
 * @brief Change the logic state if different from `newState`.
 * @param logic Reference to Logic object to update.
 * @param newState The desired new state.
 * @return true if the state was updated, false if unchanged.
 */
bool changeState(Logic &logic, const State newState) {
    if (logic.state == newState) {
        return false;
    }
    logic.state = newState;
    return true;
}
