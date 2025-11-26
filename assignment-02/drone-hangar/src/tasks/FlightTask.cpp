#include "tasks/FlightTask.h"

#include "tasks/state/flight/WaitingState.h"

FlightTask::FlightTask(HWPlatform *hw, Context *context)
    : hw(hw), context(context), state(nullptr) {
    this->changeState(new ::WaitingState);
}

FlightTask::FlightTask(HWPlatform *hw, Context *context, int period)
    : FlightTask(hw, context) {
    this->init(period);
}

void FlightTask::init(const int period) {
    Task::init(period);
}

void FlightTask::tick() {
    this->state->tick(this, this->hw, this->context);
}
