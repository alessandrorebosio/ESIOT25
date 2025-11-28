#pragma once

#include <Arduino.h>

/**
 * @brief Message service class for serial communication.
 * 
 * This class provides a simplified interface for sending and receiving messages
 * over the serial port. It handles serial initialization and message processing.
 */
class MsgService final {
  public:
	/**
	 * @brief Initializes the serial communication.
	 * 
	 * @param baud The baud rate for serial communication
	 */
	void init(unsigned int baud);

	/**
	 * @brief Checks if a message is available to read.
	 * 
	 * @return true if there is data available in the serial buffer, false otherwise
	 */
	bool isMsgAvailable();

	/**
	 * @brief Reads the available message from serial buffer.
	 * 
	 * @return The received message as a String
	 */
	String receive();

	/**
	 * @brief Sends a message over serial communication.
	 * 
	 * @param text The message to send
	 */
	void send(String text);

	/**
	 * @brief Default destructor.
	 */
	~MsgService() = default;
};
