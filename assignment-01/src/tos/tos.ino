#include <Arduino.h>
#include <avr/sleep.h>

#include "actuators.h"
#include "config.h"
#include "logic.h"
#include "output.h"
#include "timer.h"

Button BUTTONS[] = {Button(BUTTON0), Button(BUTTON1), Button(BUTTON2), Button(BUTTON3)};
uint8_t LEDS[] = {LED0, LED1, LED2, LED3};

int SEQ_LEN = MIN(LEN(BUTTONS), LEN(LEDS));

static Game game;
static Timer t0;

void setup() {
    gameInit(&game, SEQ_LEN);
    actuatorsInit();
    outputInit();
}

void loop() {
    switch (game.state) {
        case INIT:
            print("Welcome to TOS!\nPress B1 to Start");
            changeState(&game, MENU);
            timerInit(&t0, SECOND_10);
            reset(&game);
            break;

        case MENU:
            setDifficulty(&game, mapPotentiometer(A0));
            ledFade(LSLED);

            if (timer_expired(&t0)) {
                changeState(&game, SLEEP);
                turnOffAllLEDs();
                return;
            }

            if (isPressed(BUTTONS[0])) {
                print("GO! Difficulty:" + String(game.difficulty) +
                      "\nSequence: " +
                      intArrayToStringOffset(game.sequence, game.len, "", 1));
                changeState(&game, PLAYING);
                timerInit(&t0, SECOND_10);
                turnOffAllLEDs();
            }
            break;

        case PLAYING:
            if (isWin(&game)) {
                shuffle(&game);
                print("GOOD! Score: " + String(game.score) + "\nSequence: " +
                      intArrayToStringOffset(game.sequence, game.len, "", 1));
                timerInit(&t0, SECOND_10 - F * game.difficulty * game.round);
                turnOffAllLEDs();
            }

            for (int i = 0; i < SEQ_LEN; i++) {
                if (isPressed(BUTTONS[i])) {
                    if (!checkButton(&game, i))
                        changeState(&game, GAMEOVER);
                    else
                        digitalWrite(LEDS[i], HIGH);
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
            attachInterrupt(digitalPinToInterrupt(BUTTONS[0].pin), wakeUp,
                            FALLING);
            sleep_mode();
            sleep_disable();
            detachInterrupt(digitalPinToInterrupt(BUTTONS[0].pin));
            break;
        default:
            print("There is a bug");
            break;
    }
}

void wakeUp() { changeState(&game, INIT); }