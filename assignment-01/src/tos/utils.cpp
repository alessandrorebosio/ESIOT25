
#include <Arduino.h>

#include "utils.h"

/**
 * @brief Convert an integer array to an Arduino String.
 *
 * Joins the first len elements of array into a single String, inserting the
 * provided separator between values. If array is nullptr or len <= 0,
 * an empty String is returned.
 */
String intArrayToString(const int *array, int len, const char *sep) {
    String out = "";
    if (!array || len <= 0)
        return out;

    for (int i = 0; i < len; ++i) {
        if (i > 0 && sep)
            out += String(sep);
        out += String(array[i]);
    }

    return out;
}

/**
 * @brief Creates a new integer array with a fixed offset applied to each
 * element.
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
int *offset(const int *array, int len, const int value) {
    if (!array || len <= 0)
        return nullptr;

    int out[len];
    for (int i = 0; i < len; ++i) {
        out[i] = array[i] + value;
    }

    return out;
}