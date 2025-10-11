#ifndef STATE_H
#define STATE_H

#include <stdbool.h>

/**
 * @file state.h
 * @brief Game state API for Tiny Operating System (ToS) assignment.
 *
 * This header exposes a minimal, controlled interface for reading and
 * modifying the current game state. The actual state variable is
 * intentionally kept private to the implementation (`state.c`) so that
 * external modules cannot modify it directly.
 */

/**
 * @enum GameState
 * @brief Possible states of the game state machine.
 *
 * The game logic should use these values to represent the high-level
 * application state. Use @ref changeState() to transition between them.
 */
typedef enum {
    /**
     * The menu is shown and the game is waiting for user input.
     */
    MENU,
    /**
     * The game is running and gameplay is active.
     */
    PLAYING,
    /**
     * The game is over (end screen).
     */
    GAMEOVER,
} GameState;

/**
 * @brief Retrieve the current game state.
 *
 * This accessor returns the current value of the internal state. Callers
 * receive the enum value by copy; no ownership semantics apply.
 *
 * @return The current @ref GameState value.
 */
GameState getState(void);

/**
 * @brief Attempt to change the current game state.
 *
 * If the provided @p newState equals the current state, the function
 * returns false and leaves the state unchanged. Otherwise the state
 * is updated to @p newState and the function returns true.
 *
 * @param newState The desired new state to set.
 * @return true if the state was updated, false if it was already equal
 *         to @p newState.
 */
bool changeState(GameState newState);

#endif