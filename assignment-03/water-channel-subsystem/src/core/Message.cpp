#include "core/Message.h"

#define MAX_MESSAGE_SIZE 256

/**
 * @brief Default constructor.
 *
 * Initializes the message buffer and reserves space for it.
 */
Message::Message(void) : message(""), msgAvailable(false) {
    this->message.reserve(MAX_MESSAGE_SIZE);
}

/**
 * @brief Initialize serial communication.
 *
 * @param baud Baud rate for serial communication
 */
void Message::init(unsigned int baud) {
    Serial.begin(baud);

    while (!Serial) {
        ;
    }
}

/**
 * @brief Send a text message over serial.
 *
 * @param text The message to send
 */
void Message::send(String text) {
    if (text.length() > 0) {
        Serial.println(text);
    }
}

/**
 * @brief Read incoming serial data and assemble a message.
 *
 * This method reads available serial data and builds a message until a
 * newline character is received or the maximum size is reached. Only printable
 * ASCII characters (32-126) are accepted.
 */
void Message::read(void) {
    if (this->msgAvailable) {
        return;
    }

    while (Serial.available() > 0) {
        int c = Serial.read();

        if (c == '\n' || c == '\r') {
            if (this->message.length() > 0) {
                this->msgAvailable = true;
                break;
            }
        } else if (c >= 32 && c <= 126) {
            this->message += (char)c;

            if (this->message.length() >= MAX_MESSAGE_SIZE) {
                this->msgAvailable = true;
                break;
            }
        }
    }
}

/**
 * @brief Get the current received message.
 *
 * @return The current message as a String
 */
String Message::get(void) {
    return this->message;
}

/**
 * @brief Converts the message string to an integer.
 *
 * This function attempts to convert the internal message string to an integer.
 * If the conversion fails (e.g., if the string doesn't contain a valid number),
 * the function returns 0 as a default value.
 *
 * @return int The converted integer value, or 0 if conversion fails.
 */
int Message::msgToInt(void) {
    return this->message.toInt();
}

/**
 * @brief Clear the current message buffer.
 */
void Message::clear(void) {
    this->msgAvailable = false;
    this->message = "";
}

/**
 * @brief Check whether a message is available to read.
 *
 * @return Constant reference to the availability flag
 */
const bool &Message::isMessageAvailable() {
    return this->msgAvailable;
}

/**
 * @brief Compare the current message with the given text.
 *
 * @param text Text to compare with
 * @return true if messages are equal (case sensitive), false otherwise
 */
bool Message::equals(const String text) {
    return this->message.equals(text);
}

/**
 * @brief Compare the current message ignoring case.
 *
 * @param text Text to compare with
 * @return true if messages are equal ignoring case, false otherwise
 */
bool Message::equalsIgnoreCase(const String text) {
    return this->message.equalsIgnoreCase(text);
}
