#include "tasks/BlinkTask.h"

#include "tasks/states/blink/Off.h"

Blink::BlinkTask::BlinkTask(HWBlink *hw, const bool &enabled, int period) : hardware(hw), enabled(enabled), state(nullptr) {
    Task::init(period);
    this->changeState(new ::Blink::Off);
}

void Blink::BlinkTask::tick() {
    this->state->tick(*this, *this->hardware, this->enabled);
}

void Blink::BlinkTask::changeState(BlinkState *newState) {
    if (this->state != nullptr) {
        this->state->onExit(*this, *this->hardware, this->enabled);
        delete this->state;
    }
    this->state = newState;
    if (this->state != nullptr) {
        this->state->onEnter(*this, *this->hardware, this->enabled);
    }
}

Blink::BlinkTask::~BlinkTask() {
    delete this->hardware;
    delete this->state;
}
