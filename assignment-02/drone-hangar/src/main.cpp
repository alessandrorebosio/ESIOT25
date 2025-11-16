#include <Arduino.h>
#include <Button.h>
#include <Led.h>
#include <Servo.h>

#include "config.h"
#include "logic.h"

Logic logic;

void setup() { Serial.begin(BAUD); }

void loop() {
    switch (logic.state) {
        case INSIDE:
            break;
        case TAKEOFF:
            break;
        case LANDING:
            break;
        case OUTSIDE:
            break;
        case PREALARM:
            break;
        case ALARM:
            break;
    }
}
