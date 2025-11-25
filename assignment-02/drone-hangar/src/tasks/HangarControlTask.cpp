#include "tasks/HangarControlTask.h"

#include "config.h"

#define LANDING_MSG "landing"
#define TAKEOFF_MSG "takeoff"

HangarControlTask::HangarControlTask(HWPlatform *hw, MsgSerivce *msg,
                                     Context *context)
    : hw(hw), msg(msg), context(context) {
}

HangarControlTask::HangarControlTask(HWPlatform *hw, MsgSerivce *msg,
                                     Context *context, int period)
    : HangarControlTask(hw, msg, context) {
    this->init(period);
}

void HangarControlTask::init(int period) {
    Task::init(period);
    this->state = NORMAL;
    this->msg->sendMsg("normal");
}

void HangarControlTask::tick() {
    switch (this->state) {
        case NORMAL:
            this->msg->sendMsg(this->msg->getMsg());
            this->msg->sendMsg("rest");
            break;

        case OPERATING:
            break;

        case WAITING:
            break;

        case PREALARM:
            break;

        case ALARM:
            break;
    }
}
