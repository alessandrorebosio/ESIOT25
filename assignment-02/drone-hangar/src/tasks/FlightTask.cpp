#include "tasks/FlightTask.h"

#include "tasks/states/flight/Idle.h"

Flight::FlightTask::FlightTask(HWFlight *hw, Context &ctx, const bool &enabled, int period)
    : hardware(hw), context(ctx), enabled(enabled), state(nullptr) {
    Task::init(period);
    this->changeState(new ::Flight::Idle);
}

void Flight::FlightTask::tick() {
    this->state->tick(*this, *this->hardware, this->context, this->enabled);
}

void Flight::FlightTask::changeState(FlightState *newState) {
    if (this->state != nullptr) {
        this->state->onExit(*this, *this->hardware, this->context, this->enabled);
        delete this->state;
    }
    this->state = newState;
    if (this->state != nullptr) {
        this->state->onEnter(*this, *this->hardware, this->context, this->enabled);
    }
}

Flight::FlightTask::~FlightTask() {
    delete this->hardware;
    delete this->state;
}
