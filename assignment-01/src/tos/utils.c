#include "utils.h"

/**
 * @file utils.c
 * @brief Implementation of small utility functions.
 */

/**
 * @brief Return the smaller of two integers.
 *
 * This is a simple utility; no overflow or special-case handling is
 * performed beyond the usual integer comparison semantics.
 *
 * @param a First integer.
 * @param b Second integer.
 * @return The lesser of @p a and @p b.
 */
int min(int a, int b) { return (a < b) ? a : b; }