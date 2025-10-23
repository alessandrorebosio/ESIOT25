#include <avr/sleep.h>
#include "core.h"
#include "config.h"
#include "input.h"
#include "output.h"
#include "timer.h"
#include "utils.h"
#include "logic.h"

/**
 * @file core.cpp
 * @brief Implementation of the core game state machine for ToS (Test of Sequence)
 * 
 * This file contains the main game loop and state handlers that control
 * the game flow from initialization to game over and sleep modes.
 */
 
static Game game;        /** Global game instance holding all game state data */
static Timer t0;         /** Main game timer used for state timeouts */

/**
 * @brief Initialize the core game system
 * 
 * Sets up all hardware modules including input, output, and game logic.
 * Initializes the game state machine and transitions to the INIT state.
 * This function must be called once at program startup.
 */
void initCore() {
    inputInit();
    outputInit();
    gameInit(&game, SEQ_LEN);
    changeState(&game, INIT);
}

/**
 * @brief Handle the INIT state - game initialization and welcome
 * 
 * Displays welcome message, initializes the menu timer, and resets game statistics.
 * Automatically transitions to MENU state after displaying welcome message.
 */
void handleInit() {
    print("Welcome to TOS!\nPress B1 to Start");
    changeState(&game, MENU);
    timerInit(&t0, SECOND_10);
    reset(&game);
}

/**
 * @brief Handle the MENU state - difficulty selection and game start
 * 
 * Continuously reads potentiometer for difficulty setting and provides
 * visual feedback with LED fading. Handles menu timeout to sleep mode
 * and start button press to begin gameplay.
 */
void handleMenu() {
    setDifficulty(&game, POTENTIOMETER_PIN);
    ledFade(LSLED_PIN);

    if (timer_expired(&t0)) {
        changeState(&game, SLEEP);
        turnOffAllLEDs();
        return;
    }

    if (wasPressed(BUTTONS[0])) {
        print("GO! Difficulty:" + String(game.difficulty) +
              "\nSequence: " +
              intArrayToString(game.sequence, game.len, ""));
        changeState(&game, PLAYING);
        timerInit(&t0, SECOND_10);
        turnOffAllLEDs();
    }
}

/**
 * @brief Handle the PLAYING state - active gameplay
 * 
 * Manages the core gameplay loop including:
 * - Checking for sequence completion and awarding points
 * - Processing player button inputs against expected sequence
 * - Handling game timer expiration
 * - Shuffling sequences and adjusting timer based on difficulty
 * 
 * Transitions to GAMEOVER state on wrong input or timer expiration.
 */
void handlePlaying() {
    if (win(&game)) {
        shuffle(&game);
        print("GOOD! Score: " + String(game.score) + "\nSequence: " +
              intArrayToString(game.sequence, game.len, ""));
        timerInit(&t0, SECOND_10 - F * game.difficulty * game.round);
        turnOffAllLEDs();
    }

    for (int i = 0; i < SEQ_LEN; i++) {
        if (wasPressed(BUTTONS[i])) {
            if (!checkButton(&game, i))
                changeState(&game, GAMEOVER);
            else
                digitalWrite(LEDS[i], HIGH);
        }
    }

    if (timer_expired(&t0))
        changeState(&game, GAMEOVER);
}

/**
 * @brief Handle the GAMEOVER state - end of game sequence
 * 
 * Displays game over sequence with visual feedback (red LED flash),
 * shows final score, and waits before returning to INIT state.
 * Provides a clean transition for game restart.
 */
void handleGameOver() {
    turnOffAllLEDs();
    digitalWrite(LSLED_PIN, HIGH);
    delay(SECOND_2);
    digitalWrite(LSLED_PIN, LOW);

    print("Game Over\nFinal Score: " + String(game.score));
    changeState(&game, INIT);
    delay(SECOND_10);
}

/**
 * @brief Handle the SLEEP state - low power mode
 * 
 * Enters maximum power saving mode while maintaining the ability to
 * wake up via button press interrupt. Restores full operation and
 * returns to INIT state when awakened.
 */
void handleSleep() {
    print("SLEEP");
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    attachInterrupt(digitalPinToInterrupt(BUTTONS[0]), []() {
        changeState(&game, INIT);
    }, FALLING);
    sleep_mode();
    sleep_disable();
    detachInterrupt(digitalPinToInterrupt(BUTTONS[0]));
}

/**
 * @brief Handle error states - system fault recovery
 * 
 * Fallback handler for undefined or erroneous states. Provides
 * diagnostic information and attempts to recover system stability.
 * This should ideally never be called during normal operation.
 */
void handleError() { print("There is a bug"); }

/**
 * @brief Get the current game state
 * 
 * @return State The current state of the game state machine
 * 
 * Provides safe, read-only access to the current game state for
 * external modules and the main loop controller.
 */
State getGameState() { return game.state; }

/**
 * Change the current state of the game if different from `newState`.
 *
 * @param game Pointer to the Game structure (nullable).
 * @param newState Target state to set.
 * @return true if the state was changed, false otherwise.
 */
bool changeState(Game *game, const State newState) {
    if (!game)
        return false;
    if (game->state == newState)
        return false;
    game->state = newState;
    return true;
}
