#include "tasks/SystemTask.h"

#include "tasks/state/system/NormalState.h"

#include "config.h"

SystemTask::SystemTask(HWPlatform *hw, Context *context)
    : hw(hw), context(context), state(nullptr) {
    this->changeState(new NormalState());
}

SystemTask::SystemTask(HWPlatform *hw, Context *context, int period)
    : SystemTask(hw, context) {
    this->init(period);
}

void SystemTask::init(int period) {
    Task::init(period);
}

void SystemTask::tick() {
    this->state->tick(this, this->hw, this->context);
}
