#ifndef SCORE_H
#define SCORE_H

/**
 * @file score.h
 * @brief Simple score counter API.
 *
 * This module provides a minimal API to read and modify an internal
 * score counter. The score variable is private to the implementation
 * and cannot be modified directly from other translation units.
 */

/**
 * @brief Get the current score value.
 *
 * @return The current score as an integer.
 */
int getScore(void);

/**
 * @brief Increase the score by one.
 *
 * This increments the internal score counter. If callers require
 * atomic updates in a concurrent environment, they must provide the
 * necessary synchronization.
 */
void increase(void);

/**
 * @brief Reset the score to zero.
 */
void reset(void);

#endif