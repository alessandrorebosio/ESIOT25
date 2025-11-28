#include "tasks/SystemTask.h"

#include "tasks/states/system/Normal.h"

System::SystemTask::SystemTask(HWSystem *hw, Context &ctx, MsgService &msg, int period)
    : hardware(hw), context(ctx), msg(msg), state(nullptr) {
    Task::init(period);
    this->changeState(new ::System::Normal);
}

void System::SystemTask::tick() {
    this->state->tick(*this, *this->hardware, this->context, this->msg);
}

void System::SystemTask::changeState(SystemState *newState) {
    if (this->state != nullptr) {
        this->state->onExit(*this, *this->hardware, this->context, this->msg);
        delete this->state;
    }
    this->state = newState;
    if (this->state != nullptr) {
        this->state->onEnter(*this, *this->hardware, this->context, this->msg);
    }
}

System::SystemTask::~SystemTask() {
    delete this->hardware;
    delete this->state;
}
