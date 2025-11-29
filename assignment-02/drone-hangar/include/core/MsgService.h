#pragma once

#include <Arduino.h>

/**
 * @brief Message service class for serial communication.
 *
 * This class provides a simplified interface for sending and receiving messages
 * over the serial port. It handles serial initialization and message processing.
 */
class MsgService final {
  private:
    String message;

  public:
    /**
     * @brief Default constructor.
     */
    MsgService(void);

    /**
     * @brief Initializes the serial communication.
     *
     * @param baud The baud rate for serial communication
     */
    void init(unsigned int baud);

    /**
     * @brief Sends a text message over serial communication.
     *
     * @param text The message to send
     */
    void send(String text);

    /**
     * @brief Reads incoming serial data and processes it into a message.
     *
     * This method reads available serial data and builds a message until
     * a newline character is received or the maximum size is reached.
     */
    void read(void);

    /**
     * @brief Gets the current received message.
     *
     * @return The current message as a String
     */
    String get(void);

    /**
     * @brief Clears the current message buffer.
     */
    void clear(void);

    /**
     * @brief Default destructor.
     */
    ~MsgService() = default;
};
