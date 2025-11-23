#include "tasks/BlinkingTask.h"

BlinkingTask::BlinkingTask(Light *led) : led(led) {
}

BlinkingTask::BlinkingTask(Light *led, int period) : BlinkingTask(led) {
    this->init(period);
}

void BlinkingTask::init(const int period) {
    Task::init(period);
    this->isOn = false;
}

void BlinkingTask::tick() {
    if (this->isOn) {
        this->led->off();
        this->isOn = false;
    } else {
        this->led->on();
        this->isOn = true;
    }
}
