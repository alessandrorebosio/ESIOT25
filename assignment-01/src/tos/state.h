#ifndef STATE_H
#define STATE_H

#include <stdbool.h>

typedef enum {
    MENU,
    PLAYING,
    GAMEOVER,
} GameState;

GameState getState(void);

bool changeState(GameState newState);

#endif