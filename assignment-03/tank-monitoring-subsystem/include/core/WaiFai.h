#pragma once

#include <WiFi.h>

/**
 * @class WaiFai
 * @brief A simple WiFi connection manager for Arduino/ESP platforms.
 *
 * This class provides methods to connect, disconnect, reconnect, and check
 * the status of a WiFi connection using provided SSID and password credentials.
 */
class WaiFai {
  private:
    const char *ssid;
    const char *password;

  public:
    /**
     * @brief Constructs a new WaiFai instance.
     *
     * @param ssid The SSID of the WiFi network.
     * @param password The password for the WiFi network.
     */
    explicit WaiFai(const char *ssid, const char *password);

    /**
     * @brief Attempts to connect to the configured WiFi network.
     *
     * This method will block until a connection is established or fails.
     * It uses the SSID and password provided during construction.
     */
    void connect();

    /**
     * @brief Disconnects from the currently connected WiFi network.
     */
    void disconnect();

    /**
     * @brief Attempts to reconnect to the WiFi network.
     *
     * This method disconnects and then attempts to reconnect using
     * the stored credentials.
     */
    void reconnect();

    /**
     * @brief Checks if the device is currently connected to a WiFi network.
     *
     * @return true if connected, false otherwise.
     */
    bool isConnected();
};
