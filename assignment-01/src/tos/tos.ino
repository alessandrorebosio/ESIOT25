#include <Arduino.h>
#include <EnableInterrupt.h>
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

void setup() {
    for (int i = 0; i < len; i++) {
        pinMode(LED[i], OUTPUT);
        pinMode(BUTTON[i], INPUT_PULLUP);
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
            timerInit(&t, SECOND_10);
            delay(300);
            break;
        case MENU:
            ledFade(LSLED);
            print(difficulty(POT));

            if (wasPressed(0)) {
                digitalWrite(LSLED, LOW);
                changeState(PLAYING);
                print("GO!");
                delay(300);
                return;
            }

            if (timer_expired(&t)) {
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
            print("Final Score XXX");
            delay(SECOND_10);
            changeState(INIT);
            break;
        case SLEEP:
            print("SLEEP MODE");
            enableInterrupt(BUTTON[0], timerInit(&t, SECOND_10), FALLING);
            set_sleep_mode(SLEEP_MODE_PWR_DOWN);
            sleep_enable();
            sleep_mode();
            sleep_disable();
            disableInterrupt(BUTTON[0]);
            changeState(INIT);
            break;
        default:
            break;
    }
}
