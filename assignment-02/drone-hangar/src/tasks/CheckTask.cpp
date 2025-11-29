#include "tasks/CheckTask.h"

#include "tasks/states/check/Idle.h"

Check::CheckTask::CheckTask(HWCheck *hw, Context &ctx, const bool &enabled, int period)
    : hardware(hw), context(ctx), enabled(enabled), state(nullptr) {
    Task::init(period);
    this->changeState(new ::Check::Idle);
}

void Check::CheckTask::tick() {
    this->state->tick(*this, *this->hardware, this->context, this->enabled);
}

void Check::CheckTask::changeState(CheckState *newState) {
    if (this->state != nullptr) {
        this->state->onExit(*this, *this->hardware, this->context, this->enabled);
        delete this->state;
    }
    this->state = newState;
    if (this->state != nullptr) {
        this->state->onEnter(*this, *this->hardware, this->context, this->enabled);
    }
}

Check::CheckTask::~CheckTask() {
    delete this->hardware;
    delete this->state;
}
