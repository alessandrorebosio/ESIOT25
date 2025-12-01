#include "tasks/OperatingTask.h"

#include "tasks/states/operating/Idle.h"

namespace Operating {

OperatingTask::OperatingTask(HWOperating *hw, Context &ctx, int period) : hardware(hw), context(ctx), state(nullptr) {
    Task::init(period);
    this->changeState(new Idle());
}

void OperatingTask::tick() {
    this->state->tick(*this, *this->hardware, this->context);
}

void OperatingTask::changeState(OperatingState *newState) {
    if (this->state != nullptr) {
        this->state->onExit(*this, *this->hardware, this->context);
        delete this->state;
    }
    this->state = newState;
    if (this->state != nullptr) {
        this->state->onEnter(*this, *this->hardware, this->context);
    }
}

OperatingTask::~OperatingTask() {
    delete this->state;
}

} // namespace Operating
