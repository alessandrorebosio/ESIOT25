#ifndef LOGIC_H
#define LOGIC_H

#include <Arduino.h>

/**
 * @file logic.h
 * @brief State machine types and helpers for the drone hangar logic.
 *
 * Defines the possible system states and a small `Logic` struct used to
 * track the current state. A helper function `changeState` is provided
 * to update the state and indicate whether the state actually changed.
 */

/**
 * @brief Possible high-level states of the system.
 */
typedef enum {
    INSIDE,
    TAKEOFF,
    LANDING,
    OUTSIDE,
    PREALARM,
    ALARM,
} State;

/**
 * @brief Simple container for the current logic state.
 */
typedef struct {
    State state = INSIDE;
} Logic;

/**
 * @brief Change the logic state if it differs from the new state.
 * @param logic Reference to the `Logic` instance to update.
 * @param newState The desired new state.
 * @return `true` if the state was changed, `false` if unchanged.
 */
bool changeState(Logic &logic, const State newState);

#endif