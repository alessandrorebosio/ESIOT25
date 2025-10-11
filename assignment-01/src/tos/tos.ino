#include "state.h"
#include "utils.h"

const int BUTTON[] = {5, 4, 3, 2};
const int LED[] = {9, 8, 7, 6};

int len = min(LEN(BUTTON), LEN(LED));

void setup() {
    // put your setup code here, to run once:
}

void loop() {
    switch (getState()) {
        case MENU:
            break;
        case PLAYING:
            break;
        case GAMEOVER:
            break;
        default:
            break;
    }
}
