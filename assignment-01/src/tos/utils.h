#ifndef UTILS_H
#define UTILS_H

/**
 * @file utils.h
 * @brief Small utility helpers used across ToS code.
 */

/**
 * @brief Compute the number of elements in a static array.
 *
 * Example: int a[10]; LEN(a) == 10.
 *
 * @note The macro only works for statically-sized arrays. Passing a
 * pointer will yield an incorrect result.
 */
#define LEN(arr) (sizeof(arr) / sizeof((arr)[0]))

/**
 * @brief Return the smaller of two integers.
 *
 * @param a First integer.
 * @param b Second integer.
 * @return The lesser of @p a and @p b.
 */
#define MIN(a, b) ((a) < (b) ? (a) : (b))

struct LedButton {
    int led;
    int button;
};

#endif