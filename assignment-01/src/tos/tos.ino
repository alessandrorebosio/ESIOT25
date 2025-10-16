#include <Arduino.h>
#include <avr/sleep.h>

#include "logic.h"
#include "output.h"
#include "score.h"
#include "state.h"
#include "timer.h"
#include "utils.h"

const long int SECOND_10 = 10000U;
const long int SECOND_2 = 2000U;

const int LED[] = {9, 8, 7, 6};
const int BUTTON[] = {5, 4, 3, 2};
const int LSLED = 10;
const int POT = A0;

const int len = MIN(LEN(LED), LEN(BUTTON));
int diff = 0;

Timer t;
GameSequence seq;

void setup() {
    for (int i = 0; i < len; i++) {
        pinMode(LED[i], OUTPUT);
        pinMode(BUTTON[i], INPUT);
    }

    pinMode(LSLED, OUTPUT);
    pinMode(POT, INPUT);

    outputInit();
}

void loop() {
    switch (getState()) {
        case INIT:
            print("Welcome to TOS!");
            print("Press B1 to Start");
            changeState(MENU);
            reset();
            break;

        case MENU:
            ledFade(LSLED);
            diff = difficulty(POT);

            if (digitalRead(BUTTON[0])) {
                digitalWrite(LSLED, LOW);
                print("GO!");
                delay(300);
                return;
            }
            if (timer_expired(&t)) {
                digitalWrite(LSLED, LOW);
                changeState(SLEEP);
            }
            break;

        case PLAYING:
            for (int i = 0; i < len; i++) {
                if (wasPressed(i)) {
                    if (checkPlayerInput(&seq, i)) {
                        digitalWrite(LED[i], HIGH);
                        delay(200);
                        digitalWrite(LED[i], LOW);
                        if (seq.currentStep >= seq.length) {
                            delay(1000);
                            print("GOOD! Score: XXX");
                            changeState(INIT);
                        }
                    } else {
                        changeState(GAMEOVER);
                    }
                }
            }
            break;

        case GAMEOVER:
            digitalWrite(LSLED, HIGH);
            delay(SECOND_2);
            digitalWrite(LSLED, LOW);

            print("Game Over");
            print("Final Score: " + String(getScore()));

            delay(SECOND_10);
            changeState(INIT);
            break;

        case SLEEP:
            print("SLEEP");
            set_sleep_mode(SLEEP_MODE_PWR_DOWN);
            sleep_enable();
            attachInterrupt(BUTTON[0], wakeUp, LOW);
            sleep_mode();
            sleep_disable();
            detachInterrupt(BUTTON[0]);
            break;
        default:
            break;
    }
}

void wakeUp() { changeState(INIT); };
