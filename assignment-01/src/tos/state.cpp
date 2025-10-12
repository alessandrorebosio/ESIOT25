#include "state.h"
#include <stdbool.h>

/**
 * @file state.c
 * @brief Implementation of the game state API.
 *
 * The `state` variable is declared static to keep it private to this
 * translation unit. Other modules must use the functions declared in
 * `state.h` to interact with the game state.
 */

/* Internal state variable - not visible outside this file. */
static GameState state = INIT;

/**
 * @brief Get the current game state.
 *
 * Returns the current value of the game state. This is a simple
 * accessor that returns the enum value by value.
 *
 * @return The current GameState.
 */
GameState getState(void) { return state; }

/**
 * @brief Change the current game state.
 *
 * If the new state equals the current state, the function returns
 * false and no change is performed. Otherwise the state is updated and
 * the function returns true.
 *
 * @param newState The desired new state.
 * @return true if the state was changed, false if it was already equal
 *         to @p newState.
 */
bool changeState(GameState newState) {
    return (state != newState) ? (state = newState, true) : false;
}