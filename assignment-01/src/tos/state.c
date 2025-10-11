#include "state.h"
#include <stdbool.h>

static GameState state = MENU;

GameState getState(void) { return state; }

bool changeState(GameState newState) {
    if (state == newState)
        return false;

    state = newState;
    return true;
}