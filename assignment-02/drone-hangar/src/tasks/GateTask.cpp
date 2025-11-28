#include "tasks/GateTask.h"

#include "tasks/states/gate/Close.h"

Gate::GateTask::GateTask(HWGate *hw, const bool &enabled, int period) : hardware(hw), enabled(enabled), state(nullptr) {
    Task::init(period);
    this->changeState(new ::Gate::Close);
}

void Gate::GateTask::tick() {
    this->state->tick(*this, *this->hardware, this->enabled);
}

void Gate::GateTask::changeState(GateState *newState) {
    if (this->state != nullptr) {
        this->state->onExit(*this, *this->hardware, this->enabled);
        delete this->state;
    }
    this->state = newState;
    if (this->state != nullptr) {
        this->state->onEnter(*this, *this->hardware, this->enabled);
    }
}

Gate::GateTask::~GateTask() {
    delete this->hardware;
    delete this->state;
}
