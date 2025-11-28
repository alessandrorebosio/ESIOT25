#include "tasks/CheckTask.h"

#include "tasks/states/check/Idle.h"

Check::CheckTask::CheckTask(Sonar &sonar, TMP36 &temp, Context &ctx, MsgService &msg, const bool &enabled, int period)
    : hardware(sonar, temp), context(ctx), msg(msg), enabled(enabled), state(nullptr) {
    Task::init(period);
    this->changeState(new ::Check::Idle);
}

void Check::CheckTask::tick() {
    this->state->tick(*this, this->hardware, this->context, this->msg, this->enabled);
}

void Check::CheckTask::changeState(CheckState *newState) {
    if (this->state != nullptr) {
        this->state->onExit(*this, this->hardware, this->context, this->msg, this->enabled);
        delete this->state;
    }
    this->state = newState;
    if (this->state != nullptr) {
        this->state->onEnter(*this, this->hardware, this->context, this->msg, this->enabled);
    }
}

Check::CheckTask::~CheckTask() {
    delete this->state;
}
