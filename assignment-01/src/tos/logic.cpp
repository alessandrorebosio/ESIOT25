#include "logic.h"

#define ANALOG_MAX_VALUE 1023
#define LIMIT 5
#define ONE 1
#define ZERO 0

const unsigned long debounceDelay = 50;
const unsigned long FADE_INTERVAL = 15;
static unsigned long lastFadeUpdate = 0;
static int brightness = 0;
static int fadeAmount = 5;

/**
 * Initialize a Game structure.
 *
 * Allocates a new sequence array of length `len` (replacing any previous
 * allocation), sets initial counters and places the game into the INIT state.
 *
 * @param game Pointer to the Game structure to initialize. Must not be NULL.
 * @param len Length of the sequence array to allocate.
 */
void gameInit(Game *game, int len) {
    if (!game || len <= 0)
        return;

    if (game->sequence) {
        delete[] game->sequence;
        game->sequence = nullptr;
    }

    game->sequence = new int[len];
    game->len = len;
    for (int i = 0; i < len; ++i) {
        game->sequence[i] = i;
    }

    game->state = INIT;
    game->step = ZERO;
    game->score = ZERO;
    game->round = ZERO;
}

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

/**
 * Check whether the player completed a full sequence (a win).
 *
 * When a full sequence is completed this increments `score` and `round`,
 * resets `step` to zero and returns true.
 *
 * @param game Pointer to the Game structure.
 * @return true if a win was detected, false otherwise.
 */
bool win(Game *game) {
    if (!game || !game->sequence || game->len <= 0)
        return false;
    if (game->step > 0 && (game->step % game->len) == 0) {
        ++game->score;
        ++game->round;
        game->step = 0;
        return true;
    }
    return false;
}

/**
 * Shuffle the game's sequence array in-place using the Fisher-Yates
 * algorithm.
 *
 * Safe to call with a NULL game pointer; in that case the function does
 * nothing.
 *
 * @param game Pointer to the Game structure.
 */
void shuffle(Game *game) {
    if (!game || !game->sequence || game->len <= 1)
        return;

    for (int i = game->len - 1; i > 0; --i) {
        int j = random(0, i + 1);
        int tmp = game->sequence[i];
        game->sequence[i] = game->sequence[j];
        game->sequence[j] = tmp;
    }
}

/**
 * Validate the pressed button against the expected value for the current
 * step and advance the step counter by one.
 *
 * @param game Pointer to the Game structure.
 * @param buttonIndex Index of the pressed button.
 * @return true if the pressed button matches the expected value.
 */
bool checkButton(Game *game, const int buttonIndex) {
    if (!game || !game->sequence || game->len == 0)
        return false;

    int expected = game->sequence[game->step % game->len];
    game->step = (game->step + 1);
    return expected == buttonIndex;
}

/**
 * Read an analog pin and map it to a difficulty level.
 *
 * The analog range [0..ANALOG_MAX_VALUE] is mapped to [1..LIMIT] and stored
 * in `game->difficulty`.
 *
 * @param game Pointer to the Game structure.
 * @param pin Analog pin number to read.
 */
void setDifficulty(Game *game, const uint8_t pin) {
    if (!game)
        return;
    int v = analogRead(pin);
    game->difficulty = (uint8_t)map(v, 0, ANALOG_MAX_VALUE, ONE, LIMIT);
}

/**
 * Reset numeric fields of the game to their default values.
 *
 * This does not deallocate the sequence buffer; it only resets counters
 * and difficulty.
 *
 * @param game Pointer to the Game structure.
 */
void reset(Game *game) {
    if (!game)
        return;
    game->difficulty = ZERO;
    game->step = ZERO;
    game->score = ZERO;
    game->round = ZERO;
}

/**
 * Perform a non-blocking fade animation on the specified PWM pin.
 *
 * Call this frequently from the main loop; timing is handled internally
 * and the function returns immediately if it is not yet time to update
 * the brightness.
 *
 * @param pin PWM-capable digital pin.
 */
void ledFade(int pin) {
    unsigned long now = millis();
    if (now - lastFadeUpdate < FADE_INTERVAL)
        return;
    lastFadeUpdate = now;

    brightness += fadeAmount;
    if (brightness <= 0 || brightness >= 255) {
        fadeAmount = -fadeAmount;
        brightness = constrain(brightness, 0, 255);
    }

    analogWrite(pin, brightness);
}

/**
 * Debounced falling-edge detection for a digital input pin.
 *
 * Returns true only once when a stable LOW reading is detected after the
 * debounce interval. Static arrays maintain per-pin state. Pins outside
 * 0..19 return false.
 *
 * @param pin Digital pin number to read.
 * @return true if a debounced press was detected, false otherwise.
 */
bool wasPressed(const uint8_t pin) {
    if (pin >= 20)
        return false;

    static int lastButtonState[20] = {HIGH};
    static int buttonState[20] = {HIGH};
    static unsigned long lastDebounceTime[20] = {0};

    int reading = digitalRead(pin);
    unsigned long now = millis();

    if (reading != lastButtonState[pin]) {
        lastDebounceTime[pin] = now;
    }

    if ((now - lastDebounceTime[pin]) > debounceDelay) {
        if (reading != buttonState[pin]) {
            buttonState[pin] = reading;
            if (buttonState[pin] == LOW) {
                lastButtonState[pin] = reading;
                return true;
            }
        }
    }

    lastButtonState[pin] = reading;
    return false;
}