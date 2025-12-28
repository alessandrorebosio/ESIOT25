#include <Arduino.h>

#include "WiFi.h"
#include "config.h"

const char *ssid = "";
const char *password = "";

void setup_wifi() {
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

void setup() {
    setup_wifi();
}

void loop() {
}
