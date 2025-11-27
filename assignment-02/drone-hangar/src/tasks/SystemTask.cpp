#include "tasks/SystemTask.h"

#include "tasks/states/system/Normal.h"

SystemTask::SystemTask(Button &btn, Led &led, TMP36 &sensor, Context &cxt, int period)
    : hardware(btn, led, sensor), context(cxt), state(nullptr) {
    Task::init(period);
    this->changeState(new ::Normal);
}

void SystemTask::tick() {
    this->state->tick(*this, this->hardware, this->context);
}

void SystemTask::changeState(SystemState *newState) {
    if (this->state != nullptr) {
        this->state->onExit(*this, this->hardware, this->context);
        delete this->state;
    }
    this->state = newState;
    if (this->state != nullptr) {
        this->state->onEnter(*this, this->hardware, this->context);
    }
}
