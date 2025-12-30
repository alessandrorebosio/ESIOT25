#pragma once

#include <Arduino.h>

/**
 * @brief Message service for serial communication.
 *
 * This class provides a simple interface for sending and receiving messages
 * over the serial port. It handles serial initialization and message
 * processing.
 */
class Message final {
  private:
    String message;
    bool msgAvailable;

  public:
    /**
     * @brief Default constructor.
     */
    Message(void);

    /**
     * @brief Initialize serial communication.
     *
     * @param baud Baud rate for serial communication
     */
    void init(unsigned int baud);

    /**
     * @brief Send a text message over serial.
     *
     * @param text The message to send
     */
    void send(String text);

    /**
     * @brief Read incoming serial data and assemble a message.
     *
     * This method reads available serial data and builds a message until a
     * newline character is received or the maximum size is reached.
     */
    void read(void);

    /**
     * @brief Get the current received message.
     *
     * @return The current message as a String
     */
    String get(void);

    /**
     * @brief Converts the message string to an integer.
     *
     * This function attempts to convert the internal message string to an integer.
     * If the conversion fails (e.g., if the string doesn't contain a valid number),
     * the function returns 0 as a default value.
     *
     * @return int The converted integer value, or 0 if conversion fails.
     */
    int msgToInt(void);

    /**
     * @brief Clear the current message buffer.
     */
    void clear(void);

    /**
     * @brief Check whether a message is available to read.
     *
     * @return Constant reference to the availability flag
     */
    const bool &isMessageAvailable();

    /**
     * @brief Compare the current message with the given text.
     *
     * @param text Text to compare with
     * @return true if messages are equal (case sensitive), false otherwise
     */
    bool equals(String text);

    /**
     * @brief Compare the current message ignoring case.
     *
     * @param text Text to compare with
     * @return true if messages are equal ignoring case, false otherwise
     */
    bool equalsIgnoreCase(String text);

    /**
     * @brief Default destructor.
     */
    ~Message() = default;
};
