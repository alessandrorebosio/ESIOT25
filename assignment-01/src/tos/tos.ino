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

Timer t;
int diff = 0;

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

            timerInit(&t, SECOND_10);
            changeState(MENU);
            reset();
            break;
        case MENU:
            ledFade(LSLED);
            diff = difficulty(POT);

            if (digitalRead(BUTTON[0])) {
                digitalWrite(LSLED, LOW);
                changeState(PLAYING);
                print("GO!");
                return;
            }

            if (timer_expired(&t)) {
                digitalWrite(LSLED, LOW);
                changeState(SLEEP);
            }
            break;
        case PLAYING:
            print("Not implemented, skipping to Game Over...");

            changeState(GAMEOVER);
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

            if (digitalRead(BUTTON[0])) {
                changeState(INIT);
                delay(300);
            }
            break;
        default:
            break;
    }
}
