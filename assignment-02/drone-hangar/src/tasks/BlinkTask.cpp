#include "tasks/BlinkTask.h"

#include "tasks/states/blink/Off.h"

Blink::BlinkTask::BlinkTask(Led &led, const bool &enabled, int period) : led(led), enabled(enabled), state(nullptr) {
    Task::init(period);
    this->changeState(new ::Blink::Off);
}

void Blink::BlinkTask::tick() {
    this->state->tick(*this, this->led, this->enabled);
}

void Blink::BlinkTask::changeState(BlinkState *newState) {
    if (this->state != nullptr) {
        this->state->onExit(*this, this->led, this->enabled);
        delete this->state;
    }
    this->state = newState;
    if (this->state != nullptr) {
        this->state->onEnter(*this, this->led, this->enabled);
    }
}
