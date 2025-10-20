#include <Arduino.h>

#include "timer.h"
#include "utils.h"
#include "output.h"

const int BUTTONS[] = {2, 3, 4, 5};
const int LEDS[] = {6, 7, 8, 9};
const int POTENTIOMENTER = A0;
const int LSLED = 10;

const int SEQ_LEN = MIN(LEN(BUTTONS), LEN(LEDS));

static Timer t0;
int state = 0;

void setup() {
    for (int i = 0; i < SEQ_LEN; i++) {
        pinMode(BUTTONS[i], INPUT);
        pinMode(LEDS[i], OUTPUT);
    }
    pinMode(POTENTIOMENTER, INPUT);
    pinMode(LSLED, OUTPUT);
    outputInit();
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
    for (int i = 0; i < SEQ_LEN; i++) {
        digitalWrite(LEDS[i], LOW);
    }
}