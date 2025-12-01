#include "tasks/FlightTask.h"

#include "tasks/states/flight/Checking.h"

/**
 * @brief Constructs a new Flight Task object
 * @param hw Pointer to flight hardware abstraction
 * @param ctx Reference to application context
 * @param enabled Reference to enabled flag
 * @param period Task execution period in milliseconds
 */
Flight::FlightTask::FlightTask(HWFlight *hw, Context &ctx, const bool &enabled, int period)
    : hardware(hw), context(ctx), enabled(enabled), state(nullptr) {
    Task::init(period);
    this->changeState(new Checking);
}

/**
 * @brief Execute one tick of the flight state machine
 */
void Flight::FlightTask::tick() {
    this->state->tick(*this, *this->hardware, this->context, this->enabled);
}

/**
 * @brief Change the current state of the flight state machine
 * @param newState Pointer to the new state to transition to
 */
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

/**
 * @brief Destroy the Flight Task object
 */
Flight::FlightTask::~FlightTask() {
    delete this->state;
}

