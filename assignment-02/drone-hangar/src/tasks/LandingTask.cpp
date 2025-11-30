#include "tasks/LandingTask.h"
#include "tasks/states/landing/Idle.h"

Landing::LandingTask::LandingTask(HWLanding *hw, Context &ctx, const bool &enabled, int period)
    : hardware(hw), context(ctx), enabled(enabled), state(nullptr) {
    Task::init(period);
    this->changeState(new Idle());
}

void Landing::LandingTask::tick() {
        this->state->tick(*this, *this->hardware, this->context, this->enabled);
}

void Landing::LandingTask::changeState(LandingState *newState) {
    if (this->state != nullptr) {
        this->state->onExit(*this, *this->hardware, this->context, this->enabled);
        delete this->state;
    }
    this->state = newState;
    if (this->state != nullptr) {
        this->state->onEnter(*this, *this->hardware, this->context, this->enabled);
    }
}
