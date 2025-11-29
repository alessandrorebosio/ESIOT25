#include "core/MsgService.h"

#define SIZE 256

/**
 * @brief Default constructor.
 *
 * Initializes the message buffer and reserves memory for it.
 */
MsgService::MsgService(void) : message("") {
    this->message.reserve(SIZE);
}

/**
 * @brief Initializes the serial communication.
 *
 * @param baud The baud rate for serial communication
 */
void MsgService::init(unsigned int baud) {
    Serial.begin(baud);
}

/**
 * @brief Sends a text message over serial communication.
 *
 * @param text The message to send
 */
void MsgService::send(String text) {
    Serial.println(text);
}

/**
 * @brief Reads incoming serial data and processes it into a message.
 *
 * This method reads available serial data and builds a message until
 * a newline character is received or the maximum size is reached.
 * Only printable ASCII characters (32-126) are accepted.
 */
void MsgService::read(void) {
    if (!this->message.equals("")) {
        return;
    }

    while (Serial.available()) {
        int c = Serial.read();

        if (c == '\n' || c == '\r') {
            if (this->message.length() > 0) {
                break;
            }
        } else if (c >= 32 && c <= 126) {
            this->message += (char)c;

            if (this->message.length() >= SIZE) {
                break;
            }
        }
    }
}

/**
 * @brief Gets the current received message.
 *
 * @return The current message as a String
 */
String MsgService::get(void) {
    return this->message;
}

/**
 * @brief Clears the current message buffer.
 */
void MsgService::clear(void) {
    this->message = "";
}
