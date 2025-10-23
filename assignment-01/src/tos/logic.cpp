#include "logic.h"

#define ZERO 0

/**
 * Initialize a Game structure.
 *
 * Allocates a new sequence array of length `len` (replacing any previous
 * allocation), sets initial counters and places the game into the INIT state.
 *
 * @param game Pointer to the Game structure to initialize. Must not be NULL.
 * @param len Length of the sequence array to allocate.
 */
void gameInit(Game *game, int len) {
    if (!game || len <= 0)
        return;

    if (game->sequence) {
        delete[] game->sequence;
        game->sequence = nullptr;
    }

    game->sequence = new int[len];
    game->len = len;
    for (int i = 0; i < len; ++i) {
        game->sequence[i] = i;
    }

    game->state = INIT;
    game->step = ZERO;
    game->score = ZERO;
    game->round = ZERO;
}

/**
 * Check whether the player completed a full sequence (a win).
 *
 * When a full sequence is completed this increments `score` and `round`,
 * resets `step` to zero and returns true.
 *
 * @param game Pointer to the Game structure.
 * @return true if a win was detected, false otherwise.
 */
bool win(Game *game) {
    if (!game || !game->sequence || game->len <= 0)
        return false;
    if (game->step > 0 && (game->step % game->len) == 0) {
        ++game->score;
        ++game->round;
        game->step = 0;
        return true;
    }
    return false;
}

/**
 * Shuffle the game's sequence array in-place using the Fisher-Yates
 * algorithm.
 *
 * Safe to call with a NULL game pointer; in that case the function does
 * nothing.
 *
 * @param game Pointer to the Game structure.
 */
void shuffle(Game *game) {
    if (!game || !game->sequence || game->len <= 1)
        return;

    for (int i = game->len - 1; i > 0; --i) {
        int j = random(0, i + 1);
        int tmp = game->sequence[i];
        game->sequence[i] = game->sequence[j];
        game->sequence[j] = tmp;
    }
}

/**
 * Validate the pressed button against the expected value for the current
 * step and advance the step counter by one.
 *
 * @param game Pointer to the Game structure.
 * @param buttonIndex Index of the pressed button.
 * @return true if the pressed button matches the expected value.
 */
bool checkButton(Game *game, const int buttonIndex) {
    if (!game || !game->sequence || game->len == 0)
        return false;

    int expected = game->sequence[game->step % game->len];
    game->step = (game->step + 1);
    return expected == buttonIndex;
}

/**
 * Reset numeric fields of the game to their default values.
 *
 * This does not deallocate the sequence buffer; it only resets counters
 * and difficulty.
 *
 * @param game Pointer to the Game structure.
 */
void reset(Game *game) {
    if (!game)
        return;
    game->difficulty = ZERO;
    game->step = ZERO;
    game->score = ZERO;
    game->round = ZERO;
}
