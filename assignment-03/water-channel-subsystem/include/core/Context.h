#pragma once

#include <Arduino.h>

#include <Queue.h>

/**
 * @brief System context and state manager.
 *
 * This class maintains the operational mode (automatic/manual) and current
 * valve position state for the entire system. It provides a centralized
 * interface for state management and control mode transitions.
 * Response messages are managed as a FIFO queue to avoid losing messages.
 */
class Context final {
  private:
    bool automatic;
    bool virtualPerc;
    bool change;
    bool connected;
    Queue<String> responseQueue;
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
    void setMotorPerc(uint8_t position);

    bool isVirtualPerc(void);

    /**
     * @brief Gets the current valve position.
     * @return Current valve position (0-255).
     */
    uint8_t getMotorPerc(void);

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
     * @brief Sets a response message to be added to the response queue.
     *
     * Stores the provided response string in a FIFO queue. If the queue is full,
     * the oldest response will be discarded to make room for the new one.
     * The CommunicationTask should regularly check for pending responses using
     * `needResponse()` and retrieve them using `popResponse()`.
     *
     * @param response The response string to be queued. Can be empty to queue
     *                 empty messages.
     */
    void setResponse(String response);

    /**
     * @brief Gets the oldest queued response without removing it.
     *
     * Retrieves the response string at the front of the queue. This method
     * does not remove the response from the queue. Use `popResponse()` to
     * get and remove a response atomically.
     *
     * @return The oldest queued response string. Returns empty string if queue
     *         is empty.
     */
    String getResponse(void);

    /**
     * @brief Retrieves and removes the oldest queued response.
     *
     * Atomically returns the response at the front of the queue and removes it.
     * This is the preferred method for processing queued responses.
     *
     * @return The oldest queued response string. Returns empty string if queue
     *         is empty.
     */
    String popResponse(void);

    /**
     * @brief Checks if a response message is pending.
     *
     * Determines whether there is at least one non-empty response in the queue.
     * This method only checks the presence of responses without modifying them.
     *
     * @return true if at least one response is queued, false otherwise.
     */
    bool needResponse(void);

    /**
     * @brief Sets the system to unconnected state
     *
     * Marks the system as disconnected from network/communication.
     * This state is typically used when network communication is lost.
     */
    void setUnconnected(void);

    /**
     * @brief Sets the system to connected state
     *
     * Marks the system as connected to network/communication.
     * This state indicates that normal communication is established.
     */
    void setConnected(void);

    /**
     * @brief Checks if the system is connected
     * @return true if the system is connected, false otherwise
     */
    bool isConnected(void);

    /**
     * @brief Resets the context to default state.
     * Sets automatic mode and position to 0.
     */
    void reset(void);
};
