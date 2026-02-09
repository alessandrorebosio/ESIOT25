#pragma once

#include <Arduino.h>

/**
 * @brief Generic FIFO queue implementation with runtime-configurable size.
 *
 * This class implements a circular buffer-based queue for any type T.
 * When the queue is full, the oldest element is automatically discarded to make room for new ones.
 *
 * @tparam T The type of elements stored in the queue.
 */
template <typename T> class Queue final {
  private:
    T *buffer;
    uint8_t head;
    uint8_t tail;
    uint8_t maxSize;

  public:
    /**
     * @brief Constructs a new Queue object with specified capacity.
     *
     * @param size Maximum number of elements the queue can hold.
     */
    Queue(uint8_t size = 10);

    /**
     * @brief Adds an element to the back of the queue.
     *
     * If the queue is full, the oldest element will be automatically discarded
     * to make room for the new element.
     *
     * @param item The item to add to the queue.
     */
    void push(T item);

    /**
     * @brief Removes and returns the element at the front of the queue.
     *
     * @return The oldest element in the queue. Returns default-constructed T if queue is empty.
     */
    T pop(void);

    /**
     * @brief Returns the element at the front of the queue without removing it.
     *
     * @return The oldest element in the queue. Returns default-constructed T if queue is empty.
     */
    T peek(void);

    /**
     * @brief Checks if the queue is empty.
     *
     * @return true if the queue contains no elements, false otherwise.
     */
    bool isEmpty(void);

    /**
     * @brief Checks if the queue is full.
     *
     * @return true if the queue is at maximum capacity, false otherwise.
     */
    bool isFull(void);

    /**
     * @brief Returns the number of elements currently in the queue.
     *
     * @return Number of elements in the queue.
     */
    uint8_t size(void);

    /**
     * @brief Returns the maximum capacity of the queue.
     *
     * @return Maximum number of elements the queue can hold.
     */
    uint8_t capacity(void);

    /**
     * @brief Removes all elements from the queue.
     */
    void clear(void);

    /**
     * @brief Destroy the Queue object.
     */
    ~Queue();
};
