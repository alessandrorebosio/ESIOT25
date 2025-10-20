#include <Arduino.h>

const int BUTTONS[] = {2, 3, 4, 5};
const int LEDS[] = {6, 7, 8, 9};
const int POTENTIOMENTER = A0;
const int LSLED = 10;

int state = 0;

void setup() {
    for (int i = 0; i < 4; i++) {
        pinMode(BUTTONS[i], INPUT);
        pinMode(LEDS[i], OUTPUT);
    }
    pinMode(POTENTIOMENTER, INPUT);
    pinMode(LSLED, OUTPUT);
}

void loop() {
    switch (state) {
        case 0:
            break;
        default:
            break;
    }
}

void turnOffAllLEDs() {
    for (int i = 0; i < 4; i++) {
        digitalWrite(LEDS[i], LOW);
    }
}