#include <Arduino.h>
#include <Button.h>
#include <Lcd.h>
#include <Led.h>
#include <MyServo.h>
#include <Timer.h>

#include "config.h"
#include "logic.h"

Logic logic;

void setup() { Serial.begin(BAUD); }

void loop() {
    /*
        if (!t1.is_running() && temperature > temp1) {
            t1.init(T3)
        }
    */
    switch (logic.state) {
        case INSIDE:
            /*
                closeDoor

                if message avaiable "takeoff"
                    change to Takeoff, print "Takeoff", t0.init(T1)

                if (t1.is_expired())
                    change to "PREALARM", print "Prealarm"
            */
            break;
        case TAKEOFF:
            /*
                led blinking + openDoor

                if distance > D1 after t0.is_expired()
                    change to OUTSIDE, print "Drone out", turn off led
             */
            break;
        case OUTSIDE:
            /*
                closeDoor

                if message avaiable "landing" and pir detect drone presence
                    change to LANDING, print "Landing", t0.init(T2)

                if (t2.is_expired())
                    change to "PREALARM", print "Prealarm", t1.init(T4)
            */
            break;
        case LANDING:
            /*
                led blinking + openDoor

                if distance < D2 after t0.is_expired()
                    change to INSIDE, print "Inside", turn off led
             */
            break;
        case PREALARM:
            /*
                if temperature < temp1 after t1.is_expired()
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
