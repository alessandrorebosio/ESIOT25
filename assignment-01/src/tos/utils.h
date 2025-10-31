#ifndef UTILS_H
#define UTILS_H

#include <Arduino.h>

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

/**
 * @brief Converts an integer array into a String, applying an integer offset to each element.
 *
 * This function takes an input integer array, applies a constant offset to each element,
 * and concatenates all resulting values into a single Arduino String. Each value is
 * separated by the specified separator string.
 *
 * @param array   Pointer to the source integer array.
 * @param len     Number of elements in the array.
 * @param sep     Separator string to insert between elements (e.g. " ", ", ").
 * @param offset  Integer value to add to each element before conversion.
 *
 * @return A String containing all array elements with offset applied and separated by @p sep.
 *         Returns an empty String if @p array is nullptr or @p len <= 0.
 */
String intArrayToStringOffset(const int *array, int len, const char *sep, const int offset);

#endif