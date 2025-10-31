
#include <Arduino.h>

#include "utils.h"

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
String intArrayToStringOffset(const int *array, int len, const char *sep, const int offset) {
    String out = "";
    if (!array || len <= 0)
        return out;

    for (int i = 0; i < len; ++i) {
        if (i > 0 && sep)
            out += String(sep);
        out += String(array[i] + offset);
    }

    return out;
}