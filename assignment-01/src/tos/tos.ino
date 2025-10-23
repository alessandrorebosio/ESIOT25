#include <avr/sleep.h>
#include "config.h"
#include "core.h"

void setup() {
    initCore();
}

void loop() {
    switch (getGameState()) {
        case INIT:
            handleInit();
            break;
        case MENU:
            handleMenu();
            break;
        case PLAYING:
            handlePlaying();
            break;
        case GAMEOVER:
            handleGameOver();
            break;
        case SLEEP:
            handleSleep();
            break;
        default:
            handleError();
            break;
    }
}