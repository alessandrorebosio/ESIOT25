#ifndef LOGIC_H
#define LOGIC_H

#include <Arduino.h>
#include <stdbool.h>

/**
 * Game states used by the ToS finite-state machine.
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
 * Game structure holding runtime state for a single ToS session.
 *
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
 * Initialize a Game structure.
 *
 * Allocates a sequence array of length `len` (replacing any previous one),
 * initializes the numeric fields and sets the initial state to INIT.
 *
 * @param game Pointer to a Game object to initialize (must not be NULL).
 * @param len Length of the sequence to allocate.
 */
void gameInit(Game *game, int len);

/**
 * Check whether the player completed a sequence step that results in a win.
 *
 * If the player's step counter has reached a multiple of the sequence length
 * this increments the score, resets the step counter and returns true.
 */
bool win(Game *game);

/** Shuffle the sequence using Fisher-Yates in-place. */
void shuffle(Game *game);

/**
 * Validate the pressed button against the sequence.
 *
 * Returns true if the pressed button matches the expected value for the
 * current step; the step counter is advanced by one in either case.
 */
bool checkButton(Game *game, const int buttonIndex);

/** Reset numeric game fields to their defaults. */
void reset(Game *game);

#endif