#include "tasks/SweepingTask.h"

#define OPEN_TIME 2000
#define CLOSE_TIME 2000
#define OPEN_POS 180
#define CLOSE_POS 0

SweepingTask::SweepingTask(Motor *motor, Context *context)
    : motor(motor), context(context) {
    this->state = CLOSE;
}

SweepingTask::SweepingTask(Motor *motor, Context *context, int period)
    : SweepingTask(motor, context) {
    this->init(period);
}

void SweepingTask::init(int period) {
    Task::init(period);
    this->currentPos = CLOSE_POS;
    this->motor->setPosition(CLOSE_POS);
    this->motor->off();
    this->state = CLOSE;
}

void SweepingTask::tick() {
    switch (this->state) {
        case CLOSE:
            if (this->context->isStarted()) {
                if (this->state == CLOSE) {
                    this->setState(OPENING);
                    this->motor->on();
                }
            }
            break;

        case OPENING: {
            long dt = elapsedTime();
            this->currentPos = ((float)dt / OPEN_TIME) * OPEN_POS;
            this->motor->setPosition(currentPos);

            if (dt >= OPEN_TIME) {
                this->motor->setPosition(OPEN_POS);
                this->setState(OPEN);
            }
            break;
        }

        case OPEN:
            if (this->context->isStopped()) {
                if (this->state == OPEN) {
                    this->setState(CLOSING);
                    this->motor->on();
                }
            }
            break;

        case CLOSING: {
            long dt = elapsedTime();
            this->currentPos = OPEN_POS - ((float)dt / CLOSE_TIME) * OPEN_POS;
            this->motor->setPosition(currentPos);

            if (dt >= CLOSE_TIME) {
                this->motor->setPosition(CLOSE_POS);
                this->motor->off();
                this->setState(CLOSE);
            }
            break;
        }
    }
}

void SweepingTask::setState(State s) {
    this->state = s;
    this->stateStartTime = millis();
}

inline long SweepingTask::elapsedTime() {
    return millis() - this->stateStartTime;
}
