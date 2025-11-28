#include "tasks/GateTask.h"

#include "tasks/states/gate/Close.h"

Gate::GateTask::GateTask(Motor &motor, const bool &enabled, int period) : motor(motor), enabled(enabled), state(nullptr) {
    Task::init(period);
    this->changeState(new ::Gate::Close);
}

void Gate::GateTask::tick() {
    this->state->tick(*this, this->motor, this->enabled);
}

void Gate::GateTask::changeState(GateState *newState) {
    if (this->state != nullptr) {
        this->state->onExit(*this, this->motor, this->enabled);
        delete this->state;
    }
    this->state = newState;
    if (this->state != nullptr) {
        this->state->onEnter(*this, this->motor, this->enabled);
    }
}

Gate::GateTask::~GateTask() {
    delete this->state;
}
