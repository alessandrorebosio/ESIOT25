#include <Arduino.h>
#include <avr/sleep.h>

#include "logic.h"
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
        pinMode(BUTTON[i], INPUT);
    }

    pinMode(LSLED, OUTPUT);
    pinMode(POT, INPUT);

    Serial.begin(9600);
}

void loop() {
    switch (getState()) {
        case INIT:
            Serial.println("Welcome to TOS! \nPress B1 to Start");

            changeState(MENU);
            timerInit(&t, SECOND_10);
            break;
        case MENU:
            ledFade(LSLED);
            int diff = difficulty(POT);

            if (digitalRead(BUTTON[0])) {
                digitalWrite(LSLED, LOW);
                changeState(PLAYING);
                Serial.println("GO!");
                return;
            }

            if (timer_expired(&t)) {
                digitalWrite(LSLED, LOW);
                changeState(SLEEP);
            }
            break;
        case PLAYING:
            Serial.println("Not implemented, skipping to Game Over...");

            changeState(GAMEOVER);
            break;
        case GAMEOVER:
            digitalWrite(LSLED, HIGH);
            delay(SECOND_2);
            digitalWrite(LSLED, LOW);

            Serial.print("Game Over\nFinal Score: ");
            Serial.println(getScore());

            delay(SECOND_10);
            changeState(INIT);
            break;
        case SLEEP:
            Serial.println("SLEEP MODE");

            if (digitalRead(BUTTON[0]))
                changeState(INIT);
            break;
        default:
            break;
    }
}
