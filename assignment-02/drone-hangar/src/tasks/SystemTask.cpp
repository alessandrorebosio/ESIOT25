#include "tasks/SystemTask.h"

#include "config.h"

SystemTask::SystemTask(HWPlatform *hw, Context *context)
    : hw(hw), context(context) {
    this->hw->serial()->sendMsg("normal");
    this->context->startBlinking();
    this->state = NORMAL;
}

SystemTask::SystemTask(HWPlatform *hw, Context *context, int period)
    : SystemTask(hw, context) {
    this->init(period);
}

void SystemTask::init(int period) {
    Task::init(period);
}

void SystemTask::tick() {
    switch (this->state) {
        case NORMAL:
            if (this->hw->isOverTemperature(TEMP1)) {
                this->hw->serial()->sendMsg("prealarm");
                this->context->stopBlinking();
                this->setState(PREALARM);
            }
            break;

        case PREALARM:
            if (!this->hw->isOverTemperature(TEMP1)) {
                this->hw->serial()->sendMsg("normal");
                this->context->startBlinking();
                this->setState(NORMAL);
            } else if (this->elapsedTime(TIME1) &&
                       this->hw->isOverTemperature(TEMP2)) {
                this->hw->serial()->sendMsg("alarm");
                this->setState(ALARM);
            }
            break;

        case ALARM:
            if (this->hw->isPressed()) {
                this->hw->serial()->sendMsg("normal");
                this->context->startBlinking();
                this->setState(NORMAL);
            }
            break;
    }
}

void SystemTask::setState(const State state) {
    this->state = state;
    this->lastStateChange = millis();
}

bool SystemTask::elapsedTime(unsigned long int time) {
    return millis() - this->lastStateChange >= time;
}