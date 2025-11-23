#include "tasks/DistanceMeasuringTask.h"
#include "config.h"

DistanceMeasuringTask::DistanceMeasuringTask(ProximitySensor* sonar, MsgSerivce* msg,
                                              Context *context)
  : sonar(sonar), msg(msg), context(context)
{
  this->state = IDLE;
}

DistanceMeasuringTask::DistanceMeasuringTask(ProximitySensor* sonar, MsgSerivce* msg,
                                              Context *context, int period)
  : DistanceMeasuringTask(sonar, msg, context)
{
  this->init(period);
}

void DistanceMeasuringTask::init(int period) {
  Task::init(period);
  this->state = IDLE;
}

void DistanceMeasuringTask::tick() {
  switch (state) {
    case IDLE:
      if (this->context->isStarted()) {
          setState(MEASURING);
      }
      break;

    case MEASURING:
      if (this->context->isStopped()) {
          setState(IDLE);
          break;
      }

      float d = sonar->getDistance();
      this->msg->sendMsg("distance:" + String(d));
      break;
  }
}

void DistanceMeasuringTask::setState(State s) {
    this->state = s;
}
