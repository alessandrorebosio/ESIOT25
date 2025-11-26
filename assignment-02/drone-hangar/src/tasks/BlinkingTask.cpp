#include "tasks/BlinkingTask.h"

#include "tasks/state/blinking/OffState.h"

BlinkingTask::BlinkingTask(HWPlatform *hw, Context *context)
    : hw(hw), context(context), state(nullptr) {
    this->changeState(new::OffState);
}

BlinkingTask::BlinkingTask(HWPlatform *hw, Context *context, int period)
    : BlinkingTask(hw, context) {
    this->init(period);
}

void BlinkingTask::init(const int period) {
    Task::init(period);
}

void BlinkingTask::tick() {
    if (!this->context->isBlinking()) {
        this->changeState(new:: OffState);
        return;
    }

    this->state->tick(this, this->hw, this->context);
}
