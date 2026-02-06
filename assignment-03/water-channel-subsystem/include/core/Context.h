#pragma once

#include <Arduino.h>

/**
 * @brief System context and state manager.
 *
 * This class maintains the operational mode (automatic/manual) and current
 * valve position state for the entire system. It provides a centralized
 * interface for state management and control mode transitions.
 */
class Context final {
  private:
    bool automatic;
    bool unconnected;
    uint8_t position;

    unsigned long lastMsgTimestamp;

  public:
    /**
     * @brief Constructs a new Context object.
     * Initializes with default state (automatic mode, position 0).
     */
    Context(void);

    /**
     * @brief Sets the system to automatic control mode.
     * In automatic mode, valve position is controlled by system logic.
     */
    void setAutomatic(void);

    /**
     * @brief Sets the system to manual control mode.
     * In manual mode, valve position is controlled by user input.
     */
    void setManual(void);

    /**
     * @brief Sets the system to unconnected state.
     */
    void setUnconnected(void);

    /**
     * @brief Resets the unconnected state.
     */
    void resetUnconnected();

    /**
     * @brief Checks if the system is in unconnected state.
     * @return true if in unconnected state, false otherwise.
    */
    bool isUnconnected(void);

    /**
     * @brief Checks if the system is in automatic mode.
     * @return true if in automatic mode, false if in manual mode.
     */
    bool isAutomatic(void);

    /**
     * @brief Sets the current valve position.
     * @param position The valve position value (0-255).
     */
    void setPosition(uint8_t position);

    /**
     * @brief Gets the current valve position.
     * @return Current valve position (0-255).
     */
    uint8_t getPosition(void);

    /**
     * @brief Updates the timestamp of the last received message.
     * Should be called whenever a valid message is received to reset the network timeout timer.
     */
    void updateLastMsgTime(void);

    /**
     * @brief Gets the timestamp of the last received message.
     * @return Timestamp (in milliseconds) of the last received message.
     */
    unsigned long getLastMsgTime(void);

    /**
     * @brief Resets the context to default state.
     * Sets automatic mode and position to 0.
     */
    void reset(void);
};
