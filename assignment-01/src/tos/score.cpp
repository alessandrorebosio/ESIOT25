#include "score.h"

#define START_VALUE 0
#define INCREMENT 1

/**
 * @file score.c
 * @brief Implementation of a small score counter.
 *
 * The `score` variable is declared static so it is private to this
 * translation unit. Use the functions in `score.h` to interact with
 * the counter.
 */

/* Internal score counter - not visible outside this file. */
static int score = 0;

/**
 * @brief Return the current score value.
 *
 * @return Current score.
 */
int getScore(void) { return score; }

/**
 * @brief Increment the score by one.
 */
void increase(void) { score += INCREMENT; }

/**
 * @brief Reset the score counter to zero.
 */
void reset(void) { score = START_VALUE; }