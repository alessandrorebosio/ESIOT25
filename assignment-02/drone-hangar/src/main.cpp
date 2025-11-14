#include <Arduino.h>

#include "config.h"

void setup() {
    Serial.begin(BAUD);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    if (Serial.available()) {
        String s = Serial.readStringUntil('\n');
        if (s == "ON") {
            digitalWrite(LED_BUILTIN, HIGH);
        } else if (s == "OFF") {
            digitalWrite(LED_BUILTIN, LOW);
        }
    }
}
