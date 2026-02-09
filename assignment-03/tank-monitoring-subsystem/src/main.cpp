#include <Arduino.h>

#include "core/Mqtt.h"
#include "core/WaiFai.h"

#include "tasks/LedTask.h"
#include "tasks/MonitoringTask.h"

#include "config.h"

double waterLevel = 0.0;
unsigned long lastMsgTime = 0;
unsigned long updateFrequency = DEFAULT_UPDATE_FREQUENCY;
bool working = false;

static WaiFai wifi(WIFI_SSID, WIFI_PASSWORD);
static WiFiClient espClient;
static Mqtt mqtt(MQTT_SERVER, MQTT_PORT, espClient);
TaskHandle_t Task1, Task2;

/**
 * @brief MQTT callback function for handling incoming messages.
 *
 * This function is called when a message arrives on a subscribed topic.
 * It parses the payload as a 4-byte frequency value and updates the
 * global updateFrequency variable.
 *
 * @param topic The MQTT topic on which the message arrived.
 * @param payload The message payload data.
 * @param length The length of the payload data.
 */
void callback(char *topic, byte *payload, unsigned int length) {
    Serial.println(String("Message arrived on [") + topic + "] len: " + length);

    updateFrequency = 0;
    for (size_t i = 0; i < length && i < 4; ++i) {
        updateFrequency = (updateFrequency << 8) | payload[i];
    }
    Serial.println(String("Received frequency: ") + updateFrequency);
}

/**
 * @brief Arduino setup function, runs once at startup.
 *
 * Initializes serial communication, connects to WiFi, sets up MQTT,
 * and creates two FreeRTOS tasks for LED control and water level monitoring.
 */
void setup() {
    Serial.begin(9600);
    wifi.connect();

    randomSeed(micros());
    mqtt.setCallback(callback);
    mqtt.reconnect();

    working = wifi.isConnected();
    xTaskCreatePinnedToCore(LedTask::exec, "Task1", 10000, NULL, 1, &Task1, 0);
    xTaskCreatePinnedToCore(MonitoringTask::exec, "Task2", 10000, NULL, 1, &Task2, 1);
}

/**
 * @brief Arduino main loop function, runs repeatedly.
 *
 * Manages WiFi and MQTT connections, handles MQTT messages, and publishes
 * water level data at the specified update frequency.
 */
void loop() {
    working = wifi.isConnected();
    wifi.reconnect();

    if (!mqtt.isConnected()) {
        mqtt.reconnect();
    }

    mqtt.loop();

    unsigned long now = millis();
    if (now - lastMsgTime > updateFrequency) {
        lastMsgTime = now;

        char msg[50];
        dtostrf(100-waterLevel, 10, 2, msg);

        char *topic = Mqtt::createTopic(ESP_NAME, BACKEND_TOPIC);
        mqtt.publish(topic, msg);
        free(topic);
    }
}
