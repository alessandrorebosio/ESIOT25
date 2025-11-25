#include "tasks/BlinkingTask.h"

BlinkingTask::BlinkingTask(Light *led, Context *context)
    : led(led), context(context) {
}

BlinkingTask::BlinkingTask(Light *led, Context *context, int period)
    : BlinkingTask(led, context) {
    this->init(period);
}

void BlinkingTask::init(const int period) {
    Task::init(period);
    this->init();
}

void BlinkingTask::tick() {
    if (!this->context->isBlinking()) {
        this->init();
        return;
    }

    this->isOn = !this->isOn;
    if (this->isOn) {
        this->led->off();
    } else {
        this->led->on();
    }
}

void BlinkingTask::init() {
    this->isOn = false;
    this->led->off();
}
