#include "logic.h"
#include "utils.h"

#define ANALOG_MAX_VALUE 1023
#define LIMIT 4
#define ZERO 0

const unsigned long debounceDelay = 50;
const unsigned long FADE_INTERVAL = 15;
static unsigned long lastFadeUpdate = 0;
static int brightness = 0;
static int fadeAmount = 5;

void gameInit(Game *game, int len) {
    if (game->sequence) {
        delete[] game->sequence;
        game->sequence = nullptr;
    }

    game->sequence = new int[len];
    for (int i = 0; i < len; i++) {
        game->sequence[i] = i;
    }

    game->step = INIT;
}

int getScore(Game *game) { return game->step / LEN(game->sequence); }

bool changeState(Game *game, State newState) {
    return (game->state != newState) ? (game->state = newState, true) : false;
}

bool win(Game *game) {
    const int len = LEN(game->sequence);
    return len != 0 && game->step > 0 && game->step % len == 0;
}

void shuffle(Game *game) {
    const int len = LEN(game->sequence);
    if (!game || !game->sequence || len <= 1) {
        return;
    }

    for (int i = LEN(game->sequence) - 1; i > 0; --i) {
        int j = random(0, i + 1);
        int temp = game->sequence[i];
        game->sequence[i] = game->sequence[j];
        game->sequence[j] = temp;
    }
}

bool checkButton(Game *game, const int buttonIndex) {
    if (!game || !game->sequence)
        return false;
    const int len = LEN(game->sequence);
    return len != 0 && game->sequence[game->step % len] == buttonIndex;
}

void setDifficulty(Game *game, const uint8_t pin) {
    if (game) {
        game->difficulty =
            map(analogRead(pin), ZERO, ANALOG_MAX_VALUE, ZERO, LIMIT);
    }
}

void reset(Game *game) {
    game->difficulty = ZERO;
    game->step = ZERO;
}

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

bool wasPressed(const uint8_t pin) {
    static int lastButtonState[20];
    static int buttonState[20];
    static unsigned long lastDebounceTime[20];

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