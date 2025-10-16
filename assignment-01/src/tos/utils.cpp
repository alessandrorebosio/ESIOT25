#include "utils.h"

/**
 * @brief Retrieve the first element of an integer array.
 *
 * @param array Pointer to the first element of an integer array. Must not be
 * nullptr.
 * @return The value of the first element pointed to by array.
 */
int getFirst(const int *array) { return array ? array[0] : -1; }