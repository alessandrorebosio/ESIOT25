
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
        out += String(array[i] + 1);
    }

    return out;
}

int *offeset(const int *array, int len, const int value) {
    if (!array || len <= 0)
        return nullptr;

    int *out = new int[len];
    for (int i = 0; i < len; ++i) {
        out[i] = array[i] + value;
    }

    return out;
}