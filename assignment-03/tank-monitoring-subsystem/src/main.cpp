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

void callback(char *topic, byte *payload, unsigned int length) {
    Serial.println(String("Message arrived on [") + topic + "] len: " + length);

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

    working = wifi.isConnected();
    xTaskCreatePinnedToCore(LedTask::exec, "Task1", 10000, NULL, 1, &Task1, 0);
    xTaskCreatePinnedToCore(MonitoringTask::exec, "Task2", 10000, NULL, 1, &Task2, 1);
}

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
        dtostrf(waterLevel, 10, 2, msg);

        char *topic = Mqtt::createTopic(ESP_NAME, BACKEND_TOPIC);
        mqtt.publish(topic, msg);
        free(topic);
    }
}
