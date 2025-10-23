#ifndef CORE_H
#define CORE_H

#include "logic.h"
/**
 * @file core.h
 * @brief Core game state machine and handlers for ToS (Test of Sequence)
 * 
 * This header defines the finite-state machine that controls the game flow
 * and declares all state handling functions.
 */

/**
 * @brief Initialize the core game system
 * 
 * Sets up all hardware peripherals, initializes game state, and prepares
 * the system for the initial state. This should be called once at startup.
 */
void initCore();

/**
 * @brief Handle the INIT state
 * 
 * Displays welcome message and transitions to MENU state after setup.
 * Initializes timers and resets game statistics.
 */
void handleInit();

/**
 * @brief Handle the MENU state
 * 
 * Manages difficulty selection via potentiometer input, displays LED feedback,
 * and handles transition to PLAYING state when start button is pressed.
 * Includes timeout to SLEEP state after inactivity.
 */
void handleMenu();

/**
 * @brief Handle the PLAYING state
 * 
 * Core gameplay loop that processes button inputs, validates sequences,
 * updates scores, and manages game progression. Handles both successful
 * sequence completion and game over conditions.
 */
void handlePlaying();

/**
 * @brief Handle the GAMEOVER state
 * 
 * Displays final score, provides visual feedback (LED patterns), and
 * transitions back to INIT state after a delay to restart the game cycle.
 */
void handleGameOver();

/**
 * @brief Handle the SLEEP state
 * 
 * Enters low-power mode to conserve energy. Configures wake-up interrupt
 * on button press and restores full operation when awakened.
 */
void handleSleep();

/**
 * @brief Handle unexpected or error states
 * 
 * Fallback handler for undefined states. Provides error feedback and
 * attempts to recover to a known safe state (usually INIT).
 */
void handleError();

/**
 * @brief Get the current game state
 * 
 * @return State The current state of the game state machine
 * 
 * This function provides safe access to the current state for external
 * modules that need to check the game status without direct access to
 * internal state variables.
 */
State getGameState();

/**
 * Change the current game state if different from the requested state.
 *
 * Returns true when the state was changed, false if it was already equal or
 * when `game` is NULL.
 */
bool changeState(Game *game, const State newState);

#endif
