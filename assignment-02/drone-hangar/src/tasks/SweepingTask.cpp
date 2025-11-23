#include "tasks/SweepingTask.h"
#include "config.h"

#define OPEN_TIME 2000
#define CLOSE_TIME 2000
#define OPEN_POS   180
#define CLOSE_POS  0

SweepingTask::SweepingTask(Motor *motor, Context *context)
  : motor(motor), context(context)
{
  this->state = CLOSED;
}

SweepingTask::SweepingTask(Motor *motor, Context *context, int period)
  : SweepingTask(motor, context)
{
  this->init(period);
}

void SweepingTask::init(int period) {
  Task::init(period);
  this->currentPos = CLOSE_POS;
  this->motor->setPosition(CLOSE_POS);
  this->motor->off();
  this->state = CLOSED;
}

void SweepingTask::tick() {
  switch (this->state) {
    case CLOSED:
      if (this->context->isStarted()) {
        this->openDoor();
      }
      break;

    case OPENING: {
      long dt = elapsedTimeInState();
      this->currentPos = ((float)dt / OPEN_TIME) * OPEN_POS;
      this->motor->setPosition(currentPos);

      if (dt >= OPEN_TIME) {
        this->motor->setPosition(OPEN_POS);
        this->setState(OPENED);
      }
      break;
    }

    case OPENED:
      if (this->context->isStopped()) {
        this->closeDoor();
      }
      break;

    case CLOSING: {
      long dt = elapsedTimeInState();
      this->currentPos = OPEN_POS - ((float)dt / CLOSE_TIME) * OPEN_POS;
      this->motor->setPosition(currentPos);

      if (dt >= CLOSE_TIME) {
        this->motor->setPosition(CLOSE_POS);
        this->motor->off();
        this->setState(CLOSED);
      }
      break;
    }
  }
}

void SweepingTask::openDoor() {
  if (this->state == CLOSED) {
    this->setState(OPENING);
    this->motor->on();
  }
}

void SweepingTask::closeDoor() {
  if (this->state == OPENED) {
    this->setState(CLOSING);
    this->motor->on();
  }
}

void SweepingTask::setState(State s) {
  this->state = s;
  this->stateStartTime = millis();
}

inline long SweepingTask::elapsedTimeInState() {
  return millis() - this->stateStartTime;
}
