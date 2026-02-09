#include "Queue.h"

/**
 * @brief Constructs a new Queue object with specified capacity.
 */
template <typename T> Queue<T>::Queue(uint8_t size) : head(0), tail(0), maxSize(size) {
    buffer = new T[maxSize];
    this->clear();
}

/**
 * @brief Destructor that deallocates the dynamically allocated buffer.
 */
template <typename T> Queue<T>::~Queue() {
    delete[] buffer;
}

/**
 * @brief Adds an element to the back of the queue.
 */
template <typename T> void Queue<T>::push(T item) {
    if (this->isFull()) {
        head = (head + 1) % maxSize;
    }

    buffer[tail] = item;
    tail = (tail + 1) % maxSize;
}

/**
 * @brief Removes and returns the element at the front of the queue.
 */
template <typename T> T Queue<T>::pop(void) {
    if (this->isEmpty()) {
        return T();
    }

    T item = buffer[head];
    head = (head + 1) % maxSize;
    return item;
}

/**
 * @brief Returns the element at the front of the queue without removing it.
 */
template <typename T> T Queue<T>::peek(void) {
    if (this->isEmpty()) {
        return T();
    }
    return buffer[head];
}

/**
 * @brief Checks if the queue is empty.
 */
template <typename T> bool Queue<T>::isEmpty(void) {
    return head == tail;
}

/**
 * @brief Checks if the queue is full.
 */
template <typename T> bool Queue<T>::isFull(void) {
    return (tail + 1) % maxSize == head;
}

/**
 * @brief Returns the number of elements currently in the queue.
 */
template <typename T> uint8_t Queue<T>::size(void) {
    if (tail >= head) {
        return tail - head;
    }
    return maxSize - head + tail;
}

/**
 * @brief Returns the maximum capacity of the queue.
 */
template <typename T> uint8_t Queue<T>::capacity(void) {
    return maxSize;
}

/**
 * @brief Removes all elements from the queue.
 */
template <typename T> void Queue<T>::clear(void) {
    head = 0;
    tail = 0;
}

// Explicit template instantiation for String type
template class Queue<String>;