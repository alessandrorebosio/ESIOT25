#include "logic.h"
#include "output.h"
#include "score.h"
#include "state.h"
#include "timer.h"
#include "utils.h"

const long int SECOND_10 = 10000U;
const long int SECOND_2 = 2000U;

const int BUTTON[] = {5, 4, 3, 2};
const int LED[] = {9, 8, 7, 6};
const int LSLED = 10;

const int POT = 0;

int len = MIN(LEN(BUTTON), LEN(LED));

Timer t;

void setup() {
    // attachInterrupt on B1 reset time and awake on MENU state
    // attachInterrupt(digitalPinToInterrupt(BUTTON[0]), wakeUp, FALLING);

    outputInit();
}

void loop() {
    switch (getState()) {
        case INIT:
            // print("Welcome to TOS!");
            // print("Press B1 to Start");
            timerInit(&t, SECOND_10);
            changeState(MENU);
            break;
        case MENU:
            ledFade(LSLED);
            difficulty(POT);

            if (wasPressed(0)) {
                changeState(PLAYING);
                // digitalRead(LSLED, LOW);
                //print("GO!");
                // delay(300);
                return;
            }

            if (timer_expired(&t)) {
                // print("Sleep");
            }
            break;
        case PLAYING:
            if (false) { // wrong sequence gameover
                changeState(GAMEOVER);
                return;
            }

            break;
        case GAMEOVER:
            // digitalRead(LSLED, HIGH);
            // delay(SECOND_2);
            // digitalRead(LSLED, LOW);
            // print("Game Over");
            // print("Final Score XXX");
            // delay(SECOND_10);
            changeState(INIT);
            break;
        default:
            break;
    }
}

void wakeUp() { timerInit(&t, SECOND_10); }
