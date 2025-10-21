#include <Arduino.h>
#include <avr/sleep.h>

#include "logic.h"
#include "timer.h"
#include "utils.h"
#include "output.h"

const long int SECOND_10 = 10000U;
const long int SECOND_2 = 2000U;

const int BUTTONS[] = {2, 3, 4, 5};
const int LEDS[] = {6, 7, 8, 9};
const int POTENTIOMENTER = A0;
const int LSLED = 10;

const int SEQ_LEN = MIN(LEN(BUTTONS), LEN(LEDS));

static Game game;
static Timer t0;

void setup() {
    for (int i = 0; i < SEQ_LEN; i++) {
        pinMode(BUTTONS[i], INPUT);
        pinMode(LEDS[i], OUTPUT);
    }
    pinMode(POTENTIOMENTER, INPUT);
    pinMode(LSLED, OUTPUT);
    
    gameInit(&game, SEQ_LEN);
    outputInit();
}

void loop() {
    switch (game.state) {
        case INIT:
            print("Welcome to TOS!P\nress B1 to Start");
            changeState(&game, MENU);
            timerInit(&t0, SECOND_10);
            reset(&game);
            break;

        case MENU:
            setDifficulty(&game, POTENTIOMENTER);
            ledFade(LSLED);

            if (timer_expired(&t0)) {
                changeState(&game, SLEEP);
                turnOffAllLEDs();
            }

            if (wasPressed(getFirst(BUTTONS))) {
                print("GO! Difficulty:" + String(game.difficulty)
                    + "\nSequence: " + intArrayToString(game.sequence, game.len, ""));
                changeState(&game, PLAYING);
                timerInit(&t0, SECOND_10);
                turnOffAllLEDs();
            }
            break;

        case PLAYING:
            if (win(&game)) {
                shuffle(&game);
                print("GOOD! Score: " + String(game.score) + "\nSequence: "
                    + intArrayToString(game.sequence, game.len, ""));
                timerInit(&t0, SECOND_10);
                turnOffAllLEDs();
            }

            for (int i = 0; i < SEQ_LEN; i++) {
                if (wasPressed(BUTTONS[i])) {
                    if (!checkButton(&game, i)) {
                        changeState(&game, GAMEOVER);
                    } else {   
                        digitalWrite(LEDS[i], HIGH);
                    }
                }
            }

            if (timer_expired(&t0)) {
                changeState(&game, GAMEOVER);
            }
            break;

        case GAMEOVER:
            turnOffAllLEDs();

            digitalWrite(LSLED, HIGH);
            delay(SECOND_2);
            digitalWrite(LSLED, LOW);

            print("Game Over\nFinal Score: " + String(game.score));
            changeState(&game, INIT);
            delay(SECOND_10);
            break;

        case SLEEP:
            print("SLEEP");

            set_sleep_mode(SLEEP_MODE_PWR_DOWN);
            sleep_enable();
            attachInterrupt(digitalPinToInterrupt(getFirst(BUTTONS)), wakeUp,FALLING); 
            sleep_mode(); 
            sleep_disable();
            detachInterrupt(digitalPinToInterrupt(getFirst(BUTTONS)));
            break;

        default:
            print("There is a bug");
            break;
    }
}

void wakeUp() { changeState(&game, INIT); };

void turnOffAllLEDs() {
    for (int i = 0; i < SEQ_LEN; i++) {
        digitalWrite(LEDS[i], LOW);
    }
    digitalWrite(LSLED, LOW);
}