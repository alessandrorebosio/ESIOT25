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
 * @brief Convert an integer array to an Arduino String.
 *
 * Joins the first @p len elements of @p array into a single String, inserting
 * the provided separator between values. If @p array is nullptr or len <= 0,
 * an empty String is returned.
 *
 * @param array Pointer to the first element of the integer array.
 * @param len Number of elements to convert.
 * @param sep Separator string placed between elements (defaults to empty
 * string).
 * @return Arduino String representing the joined values.
 */
String intArrayToString(const int *array, int len, const char *sep);

/**
 * @brief Creates a new integer array with a fixed offset applied to each element.
 *
 * This function allocates a new array on the heap, copies all elements from the
 * source array, and adds the specified `value` to each element.
 *
 * @param array Pointer to the source array of integers.
 * @param len Number of elements in the source array.
 * @param value The offset value to add to each element.
 * @return Pointer to the newly allocated array with offset applied.
 *         Returns nullptr if the input array is nullptr or len <= 0.
 */
int *offset(const int *array, int len, const int value);

#endif