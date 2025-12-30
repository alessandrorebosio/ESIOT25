#include "core/Mqtt.h"
#include "core/WaiFai.h"
#include <Arduino.h>

#include "config.h"

const char *ssid = "";
const char *password = "";

const char *mqtt_server = "broker.mqtt-dashboard.com";
const int mqtt_port = 1883;

const char *backend = "backend";
const char *esp = "esp32";

// Variables
double waterLevel = 0.0;
unsigned long lastMsgTime = 0;
long updateFrequency = 5000;

// WiFi and MQTT instances
static WaiFai wifi(ssid, password);
static WiFiClient espClient;
static Mqtt mqtt(mqtt_server, mqtt_port, espClient);

// MQTT callback for incoming messages
void callback(char *topic, byte *payload, unsigned int length) {
    Serial.println(String("Message arrived on [") + topic + "] len: " + length);

    // Parse frequency update (assuming big-endian long)
    updateFrequency = 0;
    for (size_t i = 0; i < length && i < 4; ++i) {
        updateFrequency = (updateFrequency << 8) | payload[i];
    }
    Serial.println(String("Received frequency: ") + updateFrequency);
}

void setup() {
    Serial.begin(115200);
    wifi.connect();

    randomSeed(micros());
    mqtt.setCallback(callback);
    mqtt.reconnect();
}

void loop() {
    // Reconnect WiFi if needed
    wifi.reconnect();

    // Reconnect MQTT if needed
    if (!mqtt.isConnected()) {
        mqtt.reconnect();
        // Resubscribe after reconnection
        char *topic = Mqtt::createTopic(backend, esp);
        mqtt.subscribe(topic);
        free(topic);
    }

    // Process MQTT messages
    mqtt.loop();

    // Publish water level periodically
    unsigned long now = millis();
    if (now - lastMsgTime > updateFrequency) {
        lastMsgTime = now;

        // Format water level message
        char msg[50];
        dtostrf(waterLevel, 10, 2, msg);

        // Publish to backend
        char *topic = Mqtt::createTopic(esp, backend);
        mqtt.publish(topic, msg);
        free(topic);
    }
}
