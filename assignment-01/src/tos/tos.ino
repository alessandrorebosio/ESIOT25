#include "logic.h"
#include "output.h"
#include "score.h"
#include "state.h"
#include "timer.h"
#include "utils.h"
#include <Arduino.h>
#include <avr/sleep.h>

const long int SECOND_10 = 10000U;
const long int SECOND_2 = 2000U;

const int BUTTON[] = {5, 4, 3, 2};
const int LED[] = {9, 8, 7, 6};
const int LSLED = 10;

const int POT = A0;

int len = MIN(LEN(BUTTON), LEN(LED));

Timer t;

void setup() {
    attachInterrupt(digitalPinToInterrupt(BUTTON[0]), wakeUp, FALLING);

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
            timerInit(&t, SECOND_10);
            changeState(MENU);
            break;
        case MENU:
            ledFade(LSLED);
            difficulty(POT);

            if (wasPressed(0)) {
                changeState(PLAYING);
                digitalWrite(LSLED, LOW);
                print("GO!");
                delay(300);
                return;
            }

            if (timer_expired(&t)) {
                changeState(SLEEP);
            }
            break;
        case PLAYING:
            print("Not implemented skip to Game Over");
            if (true) { // wrong sequence gameover
                changeState(GAMEOVER);
                return;
            }

            break;
        case GAMEOVER:
            digitalWrite(LSLED, HIGH);
            delay(SECOND_2);
            digitalWrite(LSLED, LOW);
            print("Game Over");
            print("Final Score XXX");
            delay(SECOND_10);
            changeState(INIT);
            break;
        case SLEEP:
            set_sleep_mode(SLEEP_MODE_PWR_DOWN);
            sleep_enable();
            sleep_mode();
            sleep_disable();
            changeState(INIT);
            break;
        default:
            break;
    }
}

void wakeUp() { timerInit(&t, SECOND_10); }
