#include "tasks/DistanceMeasuringTask.h"
#include "config.h"

DistanceMeasuringTask::DistanceMeasuringTask(ProximitySensor *sonar,
                                             MsgService *msg, Context *context)
    : sonar(sonar), msg(msg), context(context) {
    this->state = IDLE;
}

DistanceMeasuringTask::DistanceMeasuringTask(ProximitySensor *sonar,
                                             MsgService *msg, Context *context,
                                             int period)
    : DistanceMeasuringTask(sonar, msg, context) {
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
                this->state = MEASURING;
            }
            break;

        case MEASURING:
            if (this->context->isStopped()) {
                this->state = IDLE;
                break;
            }

            this->msg->sendMsg("distance:" + String(sonar->getDistance()));
            break;
    }
}
