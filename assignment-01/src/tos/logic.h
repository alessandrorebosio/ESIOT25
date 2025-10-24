#ifndef LOGIC_H
#define LOGIC_H

#include <Arduino.h>
#include <stdbool.h>

/**
 * @file logic.h
 * @brief Core game logic types and function declarations for ToS.
 */

/**
 * @brief Game states used by the ToS finite-state machine.
 *
 * - INIT:    Initial startup state where welcome is shown.
 * - MENU:    Main menu where difficulty can be selected.
 * - PLAYING: Game is active and accepts input.
 * - GAMEOVER: End-of-game screen is shown.
 * - SLEEP:   Low-power mode until a button wakes the device.
 */
typedef enum {
    INIT,
    MENU,
    PLAYING,
    GAMEOVER,
    SLEEP,
} State;

/**
 * @brief Game structure holding runtime state for a single ToS session.
 *
 * @details
 * Fields:
 *  - difficulty: Selected difficulty level (1..5).
 *  - sequence: Pointer to a dynamically-allocated int array with the
 *              sequence indices (0-based). Ownership is with the Game.
 *  - len: Length of the sequence array.
 *  - state: Current state machine state.
 *  - step: Current step index within the active sequence (advances on
 *          each button press).
 *  - score: Number of successfully completed sequences.
 *  - round: Number of rounds played; incremented when a win is detected.
 */
typedef struct {
    uint8_t difficulty;
    int *sequence;
    int len;
    State state;
    int step;
    int score;
    int round;
} Game;

/**
 * @brief Initialize a Game structure.
 *
 * Allocates a sequence array of length `len` (replacing any previous one),
 * initializes the numeric fields and sets the initial state to INIT.
 *
 * @param game Pointer to a Game object to initialize (must not be NULL).
 * @param len Length of the sequence to allocate.
 */
void gameInit(Game *game, int len);

/**
 * @brief Change the current state of the game.
 *
 * Does nothing if the state is unchanged or if `game` is NULL.
 *
 * @param game Pointer to the Game object.
 * @param newState The new state to set.
 * @return true if the state was changed, false otherwise.
 */
bool changeState(Game *game, const State newState);

/**
 * @brief Set the global difficulty level used by the game logic.
 *
 * @param game Pointer to the Game object.
 * @param value Integer representing the difficulty level to apply.
 */
void setDifficulty(Game *game, int value);

/**
 * @brief Check whether the player completed a sequence step that results in a
 * win.
 *
 * If the player's step counter has reached a multiple of the sequence length
 * this increments the score, resets the step counter and returns true.
 *
 * @param game Pointer to the Game object.
 * @return true if a win condition was detected, false otherwise.
 */
bool isWin(Game *game);

/**
 * @brief Shuffle the sequence using Fisher-Yates in-place.
 *
 * @param game Pointer to the Game object.
 */
void shuffle(Game *game);

/**
 * @brief Validate the pressed button against the sequence.
 *
 * Returns true if the pressed button matches the expected value for the
 * current step; the step counter is advanced by one in either case.
 *
 * @param game Pointer to the Game object.
 * @param buttonIndex Index of the pressed button.
 * @return true if the pressed button matches the expected value.
 */
bool checkButton(Game *game, const int buttonIndex);

/**
 * @brief Reset numeric game fields to their defaults.
 *
 * Does not deallocate the sequence buffer; it only resets counters and
 * difficulty.
 *
 * @param game Pointer to the Game object.
 */
void reset(Game *game);

#endif