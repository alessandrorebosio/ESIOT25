#include <Arduino.h>

#include "core/WaiFai.h"

#include "config.h"

const char *ssid = "";
const char *password = "";

static WaiFai wifi(ssid, password);

void setup() {
    Serial.begin(115200);
    wifi.connect();
}

void loop() {
    wifi.reconnect();
    delay(5000);
}
