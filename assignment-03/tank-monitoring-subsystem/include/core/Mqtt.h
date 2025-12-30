#pragma once

#include <PubSubClient.h>
#include <WiFi.h>

/**
 * @class Mqtt
 * @brief MQTT client wrapper for ESP32/Arduino platforms.
 *
 * This class provides a simplified interface for MQTT communication,
 * handling connection management, publishing, subscribing, and message
 * callbacks using the PubSubClient library.
 */
class Mqtt {
  private:
    PubSubClient client;
    const char *server;
    int port;

  public:
    /**
     * @brief Constructs a new Mqtt client.
     *
     * @param server MQTT broker server address (IP or hostname)
     * @param port MQTT broker port (typically 1883 for plain, 8883 for TLS)
     * @param wifiClient Reference to a WiFiClient instance for network communication
     */
    Mqtt(const char *server, int port, WiFiClient &wifiClient);

    /**
     * @brief Sets the callback function for incoming MQTT messages.
     *
     * @param callback Function pointer to the message handler callback
     */
    void setCallback(MQTT_CALLBACK_SIGNATURE);

    /**
     * @brief Subscribes to an MQTT topic.
     *
     * @param topic The topic to subscribe to
     */
    void subscribe(const char *topic);

    /**
     * @brief Attempts to reconnect to the MQTT broker if disconnected.
     *
     * @param clientIdPrefix Prefix for generating a random client ID (default: "esiot-client-")
     */
    void reconnect(const char *clientIdPrefix = "esiot-client-");

    /**
     * @brief Publishes a message to an MQTT topic.
     *
     * @param topic The topic to publish to
     * @param payload The message payload
     * @return true if published successfully, false otherwise
     */
    bool publish(const char *topic, const char *payload);

    /**
     * @brief Checks if the client is connected to the MQTT broker.
     *
     * @return true if connected, false otherwise
     */
    bool isConnected();

    /**
     * @brief Processes incoming MQTT messages and maintains the connection.
     *
     * Should be called regularly in the main loop.
     */
    void loop();

    /**
     * @brief Creates a formatted MQTT topic string.
     *
     * Creates a topic in the format: "RiverMonitoring/<source>/<destination>"
     *
     * @param source Source identifier
     * @param destination Destination identifier
     * @return Dynamically allocated char* with the topic string (caller must free)
     */
    static char *createTopic(const char *source, const char *destination);
};
