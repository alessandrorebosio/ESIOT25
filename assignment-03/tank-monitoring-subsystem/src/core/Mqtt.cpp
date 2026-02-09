#include "core/Mqtt.h"

/**
 * @brief Constructs a new Mqtt client.
 *
 * Initializes the MQTT client with broker details and sets up the server connection.
 *
 * @param server MQTT broker server address
 * @param port MQTT broker port
 * @param wifiClient Reference to a WiFiClient instance
 */
Mqtt::Mqtt(const char *server, int port, WiFiClient &wifiClient) : client(wifiClient), server(server), port(port) {
    client.setServer(server, port);
}

/**
 * @brief Sets the callback function for incoming MQTT messages.
 *
 * @param callback Function pointer to the message handler callback
 */
void Mqtt::setCallback(MQTT_CALLBACK_SIGNATURE) {
    client.setCallback(callback);
}

/**
 * @brief Subscribes to an MQTT topic.
 *
 * Only subscribes if the client is currently connected to the broker.
 *
 * @param topic The topic to subscribe to
 */
void Mqtt::subscribe(const char *topic) {
    if (client.connected()) {
        client.subscribe(topic);
        Serial.println(String("Subscribed to: ") + topic);
    } else {
        Serial.println("Cannot subscribe: MQTT not connected");
    }
}

/**
 * @brief Attempts to reconnect to the MQTT broker if disconnected.
 *
 * This is a blocking method that will continuously attempt to reconnect
 * until successful. Generates a random client ID using the provided prefix.
 *
 * @param clientIdPrefix Prefix for the client ID (default: "esiot-client-")
 */
void Mqtt::reconnect(const char *clientIdPrefix) {
    while (!client.connected()) {
        Serial.print("Attempting MQTT connection...");

        // Create a random client ID
        String clientId = String(clientIdPrefix) + String(random(0xffff), HEX);

        // Attempt to connect
        if (client.connect(clientId.c_str())) {
            Serial.println("connected");
        } else {
            Serial.print("failed, rc=");
            Serial.print(client.state());
            Serial.println(" try again in 5 seconds");
            delay(5000);
        }
    }
}

/**
 * @brief Publishes a message to an MQTT topic.
 *
 * Only publishes if the client is currently connected to the broker.
 *
 * @param topic The topic to publish to
 * @param payload The message payload
 * @return true if published successfully, false otherwise
 */
bool Mqtt::publish(const char *topic, const char *payload) {
    if (client.connected()) {
        Serial.println(String("Publishing to ") + topic + ": " + payload);
        return client.publish(topic, payload);
    } else {
        Serial.println("Cannot publish: MQTT not connected");
        return false;
    }
}

/**
 * @brief Checks if the client is connected to the MQTT broker.
 *
 * @return true if connected, false otherwise
 */
bool Mqtt::isConnected() {
    return client.connected();
}

/**
 * @brief Processes incoming MQTT messages and maintains the connection.
 *
 * Should be called regularly in the main loop to handle MQTT communication.
 */
void Mqtt::loop() {
    client.loop();
}

/**
 * @brief Creates a formatted MQTT topic string.
 *
 * Creates a topic in the format: "SmartTank/<source>/<destination>"
 * Memory is dynamically allocated and must be freed by the caller.
 *
 * @param source Source identifier
 * @param destination Destination identifier
 * @return Dynamically allocated char* with the topic string, or NULL on allocation failure
 */
char *Mqtt::createTopic(const char *source, const char *destination) {
    // Calculate the length of the resulting string
    size_t length = strlen("SmartTank/") + strlen(source) + strlen("/") + strlen(destination) + 1;

    // Allocate memory for the resulting string
    char *result = (char *)malloc(length);

    // Check for allocation failure
    if (result == NULL) {
        Serial.println("Memory allocation error for topic");
        return NULL;
    }

    // Construct the resulting string
    snprintf(result, length, "SmartTank/%s/%s", source, destination);
    return result;
}
