#include "tasks/SweepingTask.h"

#define SWP_TIME 2000
#define OPEN_POS 180
#define CLOSE_POS 0

SweepingTask::SweepingTask(Motor *motor, Context *context)
    : motor(motor), context(context) {
    this->reset();
}

SweepingTask::SweepingTask(Motor *motor, Context *context, int period)
    : SweepingTask(motor, context) {
    this->init(period);
}

void SweepingTask::init(int period) {
    Task::init(period);
    this->reset();
}

void SweepingTask::tick() {
    bool contextName = this->context->shouldOpen();
    long dt = this->elapsedTime();

    switch (this->state) {
        case CLOSE:
            if (contextName) {
                this->setState(OPENING);
                this->motor->on();
            }
            break;

        case OPENING: {
            if (!contextName) {
                this->setState(CLOSING);
                this->motor->on();
                return;
            }

            this->motor->setPosition(CLOSE_POS + (float)dt / SWP_TIME *
                                                     (OPEN_POS - CLOSE_POS));

            if (dt >= SWP_TIME) {
                this->motor->setPosition(OPEN_POS);
                this->motor->off();
                this->setState(OPEN);
            }
            break;
        }

        case OPEN:
            if (!contextName) {
                this->setState(CLOSING);
                this->motor->on();
            }
            break;

        case CLOSING: {
            if (contextName) {
                this->setState(OPENING);
                this->motor->on();
                return;
            }

            this->motor->setPosition(OPEN_POS - (float)dt / SWP_TIME *
                                                    (OPEN_POS - CLOSE_POS));

            if (dt >= SWP_TIME) {
                this->motor->setPosition(CLOSE_POS);
                this->motor->off();
                this->setState(CLOSE);
            }
            break;
        }
    }
}

void SweepingTask::reset() {
    this->motor->setPosition(CLOSE_POS);
    this->motor->off();

    this->state = CLOSE;
    this->stateStartTime = millis();
}

void SweepingTask::setState(State s) {
    this->state = s;
    this->stateStartTime = millis();
}

inline long SweepingTask::elapsedTime() {
    return millis() - this->stateStartTime;
}
