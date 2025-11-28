#include "tasks/FlightTask.h"

#include "tasks/states/flight/Idle.h"

Flight::FlightTask::FlightTask(Pir &pir, Sonar &sonar, TMP36 &temp, Context &ctx, MsgService &msg, const bool &enabled, int period)
    : hardware(pir, sonar, temp), context(ctx), msg(msg), enabled(enabled), state(nullptr) {
    Task::init(period);
    this->changeState(new ::Flight::Idle);
}

void Flight::FlightTask::tick() {
    this->state->tick(*this, this->hardware, this->context, this->msg, this->enabled);
}

void Flight::FlightTask::changeState(FlightState *newState) {
    if (this->state != nullptr) {
        this->state->onExit(*this, this->hardware, this->context, this->msg, this->enabled);
        delete this->state;
    }
    this->state = newState;
    if (this->state != nullptr) {
        this->state->onEnter(*this, this->hardware, this->context, this->msg, this->enabled);
    }
}

Flight::FlightTask::~FlightTask() {
    delete this->state;
}
