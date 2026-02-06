#include "core/Context.h"

/**
 * @brief Constructs a new Context object and initializes it to default state.
 * Calls reset() to set automatic mode and position 0.
 */
Context::Context(void) {
    this->reset();
}

/**
 * @brief Resets the context to default state.
 * Sets operation mode to automatic and position to 0.
 */
void Context::reset(void) {
    this->setAutomatic();
    this->lastMsgTime = 0;
    this->position = 0;
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
 * @param position The valve position value (0-255).
 */
void Context::setPosition(uint8_t position) {
    this->position = position;
}

/**
 * @brief Gets the current valve position.
 * @return Current valve position (0-255).
 */
uint8_t Context::getPosition(void) {
    return this->position;
}

/**
 * @brief Updates the timestamp of the last received message.
 * Should be called whenever a valid message is received to reset the network timeout timer.
 */
void Context::updateLastMsgTime(void) {
    this->lastMsgTime = millis();
}

/**
 * @brief Gets the timestamp of the last received message.
 * @return Timestamp (in milliseconds) of the last received message.
 */
unsigned long Context::getLastMsgTime(void) {
    return this->lastMsgTime;
}

void Context::changeTo(void) {
    this->change = true;
}

bool Context::needChange(void) {
    bool result = this->change;
    this->change = false;
    return result;
}
