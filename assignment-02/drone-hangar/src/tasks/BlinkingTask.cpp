#include "tasks/BlinkingTask.h"

void BlinkingTask::init(const int period) {
    Task::init(period);
    this->state = OFF;
}

void BlinkingTask::tick() {
    switch (this->state) {
        case OFF:
            this->led->on();
            this->state = ON;
            break;
        case ON:
            this->led->off();
            this->state = OFF;
            break;
    }
}
