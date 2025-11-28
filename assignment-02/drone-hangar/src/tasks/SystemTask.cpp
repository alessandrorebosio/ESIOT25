#include "tasks/SystemTask.h"

#include "tasks/states/system/Normal.h"

SystemTask::SystemTask(Button &btn, Led &led, TMP36 &sensor, Context &ctx, MsgService &msg, int period)
    : hardware(btn, led, sensor), context(ctx), msg(msg), state(nullptr) {
    Task::init(period);
    this->changeState(new ::Normal);
}

void SystemTask::tick() {
    this->state->tick(*this, this->hardware, this->context, this->msg);
}

void SystemTask::changeState(SystemState *newState) {
    if (this->state != nullptr) {
        this->state->onExit(*this, this->hardware, this->context, this->msg);
        delete this->state;
    }
    this->state = newState;
    if (this->state != nullptr) {
        this->state->onEnter(*this, this->hardware, this->context, this->msg);
    }
}
