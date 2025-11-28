#include "core/MsgService.h"

/**
 * @brief Initializes the serial communication.
 * 
 * @param baud The baud rate for serial communication
 */
void MsgService::init(unsigned int baud) {
    Serial.begin(baud);
}

/**
 * @brief Sends a message over serial communication.
 * 
 * @param text The message to send
 */
void MsgService::send(const String text) {
    Serial.println(text);
}

/**
 * @brief Checks if a message is available to read.
 * 
 * @return true if there is data available in the serial buffer, false otherwise
 */
bool MsgService::isMsgAvailable() {
    return Serial.available() > 0;
}

/**
 * @brief Reads the available message from serial buffer.
 * 
 * Reads all available characters from the serial buffer and returns them as a String.
 * 
 * @return The received message as a String
 */
String MsgService::receive() {
    String msg = "";
    while (this->isMsgAvailable()) {
        msg += (char)Serial.read();
    }
    return msg;
}
