#include "tasks/CheckTask.h"

#include "tasks/state/check/IdleState.h"

CheckTask::CheckTask(HWPlatform *hw, Context *context) 
    : hw(hw), context(context), state(nullptr) {
    this->changeState(new ::IdleState);
}

CheckTask::CheckTask(HWPlatform *hw, Context *context, int period)
    : CheckTask(hw, context) {
    this->init(period);
}

void CheckTask::init(int period) {
    Task::init(period);
}

void CheckTask::tick() {
    this->state->tick(this, this->hw, this->context);
}