#include <Arduino.h>
#include <Button.h>
#include <Led.h>
#include <Servo.h>
#include <Timer.h>

#include "config.h"
#include "logic.h"

Button button;
Logic logic;

void setup() { Serial.begin(BAUD); }

void loop() {
    switch (logic.state) {
        case INSIDE:
            /*
                closeDoor

                if message avaiable "takeoff"
                    change to Takeoff, print "Takeoff"

                if temperature > temp1 after T3
                    change to "PREALARM", print "Prealarm"
            */
            break;
        case TAKEOFF:
            /*
                led blinking + openDoor

                if distance > D1 after T1
                    change to OUTSIDE, print "Drone out", turn off led
             */
            break;
        case OUTSIDE:
            /*
                closeDoor

                if message avaiable "landing" and pir detect drone presence
                    change to LANDING, print "Landing"

                if temperature > temp1 after T3
                    change to "PREALARM", print "Prealarm"
            */
            break;
        case LANDING:
            /*
                led blinking + openDoor

                if distance < D2 after T2
                    change to INSIDE, print "Inside", turn off led
             */
            break;
        case PREALARM:
            /*
                if temperature < temp1 after T4
                    return to previous state
                else
                    change to ALARM, print "Alarm"
            */
            break;
        case ALARM:
            /*
                closeDoor + turn on L3

                if button.isPressed()
                    return to previous state
             */
            break;
    }
}
