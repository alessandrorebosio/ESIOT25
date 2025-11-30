#include "tasks/TakeOffTask.h"
#include "tasks/states/takeoff/Idle.h"

TakeOff::TakeOffTask::TakeOffTask(HWTakeOff *hw, Context &ctx, const bool &enabled, int period)
    : hardware(hw), context(ctx), enabled(enabled), state(nullptr) {
    Task::init(period);
    this->changeState(new Idle());
}

void TakeOff::TakeOffTask::tick() {
        this->state->tick(*this, *this->hardware, this->context, this->enabled);
}

void TakeOff::TakeOffTask::changeState(TakeOffState *newState) {
    if (this->state != nullptr) {
        this->state->onExit(*this, *this->hardware, this->context, this->enabled);
        delete this->state;
    }
    this->state = newState;
    if (this->state != nullptr) {
        this->state->onEnter(*this, *this->hardware, this->context, this->enabled);
    }
}
