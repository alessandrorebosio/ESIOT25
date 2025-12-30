#include "core/WaiFai.h"

/**
 * @brief Constructs a new WaiFai instance.
 *
 * Initializes the WiFi manager with the provided network credentials.
 *
 * @param ssid The SSID (network name) to connect to.
 * @param password The password for the WiFi network.
 */
WaiFai::WaiFai(const char *ssid, const char *password) : ssid(ssid), password(password) {
}

/**
 * @brief Attempts to connect to the configured WiFi network.
 */
void WaiFai::connect() {
    Serial.println(String("Connecting to ") + ssid);

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

/**
 * @brief Disconnects from the currently connected WiFi network.
 *
 * Ends the current WiFi connection and prints a confirmation message.
 */
void WaiFai::disconnect() {
    WiFi.disconnect();
    Serial.println("WiFi disconnected");
}

/**
 * @brief Attempts to reconnect to the WiFi network if not currently connected.
 *
 * Checks the current connection status. If disconnected, it calls connect()
 * to re-establish the connection.
 */
void WaiFai::reconnect() {
    if (!this->isConnected()) {
        Serial.println("WiFi connection lost. Reconnecting...");
        this->connect();
    }
}

/**
 * @brief Checks if the device is currently connected to a WiFi network.
 *
 * @return true if WiFi status is WL_CONNECTED, false otherwise.
 */
bool WaiFai::isConnected() {
    return WiFi.status() == WL_CONNECTED;
}
