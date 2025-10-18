#include <Arduino.h>
#include <avr/sleep.h>

#include "logic.h"
#include "output.h"
#include "state.h"
#include "timer.h"
#include "utils.h"

const long int SECOND_10 = 10000U;
const long int SECOND_2 = 2000U;

const int LED[] = {6, 7, 8, 9};
const int BUTTON[] = {2, 3, 4, 5};
const int LSLED = 10;
const int POT = A0;

const int LEN = MIN(LEN(LED), LEN(BUTTON));
int diff = 0;

Timer t0;

void setup() {
    for (int i = 0; i < LEN; i++) {
        pinMode(BUTTON[i], INPUT);
        pinMode(LED[i], OUTPUT);
    }

    pinMode(LSLED, OUTPUT);
    pinMode(POT, INPUT);

    outputInit();
    gameInit(LEN);
}

void loop() {
    switch (getState()) {
        case INIT:
            print("Welcome to TOS!\nPress B1 to Start");
            reset();
            changeState(MENU);
            break;

        case MENU:
            diff = difficulty(POT);
            ledFade(LSLED);

            if (digitalRead(getFirst(BUTTON))) {
                digitalWrite(LSLED, LOW);
                changeState(PLAYING);
                print("GO!");
                delay(300);
                return;
            }
            if (timer_expired(&t0)) {
                digitalWrite(LSLED, LOW);
                changeState(SLEEP);
            }
            break;

        case PLAYING:
            if (needsNewSequence()) {
                shuffleSequence();

                int *seq = getSequence();
                String seqStr = "";
                for (int i = 0; i < LEN; i++) {
                    seqStr += String(seq[i]+1) + "";
                }
                print("Sequence: "+seqStr);
            }

            for (int i = 0; i < LEN; i++) {
                if(isSequenceCompleted()) {
                        reset();
                        turnOffAllLEDs();
                        increaseScore();
                        print("GOOD!\nScore: " + String(getScore()));
                        delay(800);
                }
                if (wasPressed(BUTTON[i])) {
                    if (!checkButton(i) || timer_expired(&t0)) {
                        changeState(GAMEOVER);
                        break;
                    } else {
                        digitalWrite(LED[i], HIGH);
                        delay(300);
                    }
                }
            }
            break;

        case GAMEOVER:
            turnOffAllLEDs();
            digitalWrite(LSLED, HIGH);
            delay(SECOND_2);
            digitalWrite(LSLED, LOW);

            print("Game Over\nFinal Score: " + String(getScore()));

            delay(SECOND_10);
            changeState(INIT);
            break;

        case SLEEP:
            print("SLEEP");
            set_sleep_mode(SLEEP_MODE_PWR_DOWN);
            sleep_enable();
            attachInterrupt(getFirst(BUTTON), wakeUp, LOW);
            sleep_mode();
            sleep_disable();
            detachInterrupt(getFirst(BUTTON));
            break;
        default:
            break;
    }
}

void wakeUp() { changeState(INIT); };

void turnOffAllLEDs() {
    for (int i = 0; i < LEN; i++) {
        digitalWrite(LED[i], LOW);
    }
}
