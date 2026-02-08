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
    bool change;
    String response;
    uint8_t position;

    unsigned long lastMsgTime;

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
     * @brief Signals that a mode change is pending.
     *
     * This method sets an internal flag indicating that the system needs to
     * switch between automatic and manual modes. The change will be processed
     * by the appropriate tasks when they check for pending changes.
     */
    void changeTo(void);

    /**
     * @brief Checks if a mode change is pending.
     *
     * This method returns whether a mode change has been requested and
     * automatically clears the change flag. This ensures each change request
     * is only processed once.
     *
     * @return true if a mode change is pending, false otherwise.
     */
    bool needChange(void);

    /**
     * @brief Sets a response message to be sent via communication interface.
     *
     * This method stores a response string that will be sent through the
     * communication interface. It's typically used for acknowledging commands
     * or sending status updates to external controllers.
     *
     * @param response The response string to be sent.
     */
    void setResponse(String response);

    /**
     * @brief Gets the current response message.
     *
     * This method retrieves the response string that was previously set
     * to be sent via the communication interface.
     *
     * @return The current response string. Returns empty string if no
     *         response is pending.
     */
    String getResponse(void);

    /**
     * @brief Checks if a response message is pending.
     *
     * This method checks whether there is a response message waiting to be
     * sent through the communication interface. It does not clear the
     * response string.
     *
     * @return true if a response message is pending, false otherwise.
     */
    bool needResponse(void);

    /**
     * @brief Resets the context to default state.
     * Sets automatic mode and position to 0.
     */
    void reset(void);
};
