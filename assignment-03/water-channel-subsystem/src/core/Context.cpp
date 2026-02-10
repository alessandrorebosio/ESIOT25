#include "core/Context.h"

/**
 * @brief Constructs a new Context object and initializes it to default state.
 * Calls reset() to set automatic mode and position 0.
 */
Context::Context(void) : responseQueue(10) {
    this->reset();
}

/**
 * @brief Resets the context to default state.
 * Sets operation mode to automatic and position to 0.
 */
void Context::reset(void) {
    this->setAutomatic();
    this->recordLastMessageTime();
    this->setValvePercentage(0);
    this->responseQueue.clear();
    this->virtualPerc = false;
    this->change = false;
    this->connected = false;
}

/**
 * @brief Sets the system to automatic control mode.
 * Valve position will be controlled by system logic.
 */
void Context::setAutomatic(void) {
    this->automatic = true;
}

/**
 * @brief Sets the system to manual control mode.
 * Valve position will be controlled by user input.
 */
void Context::setManual(void) {
    this->automatic = false;
}

/**
 * @brief Checks if the system is in automatic mode.
 * @return true if in automatic mode, false if in manual mode.
 */
bool Context::isAutomatic(void) {
    return this->automatic;
}

/**
 * @brief Sets the current valve position.
 * @param position The valve position percentage (0-100).
 */
void Context::setValvePercentage(uint8_t position) {
    this->position = position;
    this->virtualPerc = true;
}

/**
 * @brief Gets the current valve position.
 * @return Current valve position percentage (0-100).
 */
uint8_t Context::getValvePercentage(void) {
    return this->position;
}

bool Context::consumePendingValvePercentage(void) {
    bool result = this->virtualPerc;
    this->virtualPerc = false;
    return result;
}

/**
 * @brief Updates the timestamp of the last received message.
 * Should be called whenever a valid message is received to reset the network timeout timer.
 */
void Context::recordLastMessageTime(void) {
    this->lastMsgTime = millis();
}

/**
 * @brief Gets the timestamp of the last received message.
 * @return Timestamp (in milliseconds) of the last received message.
 */
unsigned long Context::getLastMsgTime(void) {
    return this->lastMsgTime;
}

/**
 * @brief Signals that a mode change is pending.
 *
 * Sets an internal flag to indicate that the system should switch between
 * automatic and manual modes. The actual mode change is determined by the
 * current state and will be applied when `consumeModeToggleRequest()` is called and
 * returns true.
 */
void Context::requestModeToggle(void) {
    this->change = true;
}

/**
 * @brief Checks if a mode change is pending.
 *
 * Returns the current state of the change flag and automatically resets it
 * to false. This ensures that each change request is processed exactly once
 * by the calling task.
 *
 * @return true if a mode change was requested, false otherwise.
 */
bool Context::consumeModeToggleRequest(void) {
    bool result = this->change;
    this->change = false;
    return result;
}

/**
 * @brief Sets a response message to be added to the response queue.
 *
 * Stores the provided response string in a FIFO queue. If the queue is full,
 * the oldest response will be discarded to make room for the new one.
 *
 * @param response The response string to be queued.
 */
void Context::setResponse(String response) {
    this->responseQueue.push(response);
}

/**
 * @brief Gets the oldest queued response without removing it.
 *
 * @return The oldest queued response string. Returns empty string if queue is empty.
 */
String Context::getResponse(void) {
    return this->responseQueue.peek();
}

/**
 * @brief Retrieves and removes the oldest queued response.
 *
 * Atomically returns the response at the front of the queue and removes it.
 *
 * @return The oldest queued response string. Returns empty string if queue is empty.
 */
String Context::popResponse(void) {
    return this->responseQueue.pop();
}

/**
 * @brief Checks if a response message is pending.
 *
 * @return true if at least one response is queued, false otherwise.
 */
bool Context::needResponse(void) {
    return !this->responseQueue.isEmpty();
}

/**
 * @brief Sets the system to unconnected state
 *
 * Marks the system as disconnected from network/communication.
 */
void Context::setDisconnected(void) {
    this->connected = false;
}

/**
 * @brief Sets the system to connected state
 *
 * Marks the system as connected to network/communication.
 */
void Context::setConnected(void) {
    this->connected = true;
}

/**
 * @brief Checks if the system is connected
 * @return true if the system is connected, false otherwise
 */
bool Context::isConnected(void) {
    return this->connected;
}
