#ifndef LOGIC_H
#define LOGIC_H

#include <Arduino.h>
#include <stdbool.h>

typedef enum {
    INIT,
    MENU,
    PLAYING,
    GAMEOVER,
    SLEEP,
} State;

typedef struct {
    uint8_t difficulty;
    int *sequence;
    State state;
    int step;
} Game;

void gameInit(Game *game, int len);

int getScore(Game *game);

bool changeState(Game *game, State newState);

bool win(Game *game);

void shuffle(Game *game);

bool checkButton(Game *game, const int buttonIndex);

void setDifficulty(Game *game, const uint8_t pin);

void reset(Game *game);

void ledFade(int pin);

bool wasPressed(const uint8_t pin);

#endif