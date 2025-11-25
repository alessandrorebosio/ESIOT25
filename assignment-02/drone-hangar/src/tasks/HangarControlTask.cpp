#include "tasks/HangarControlTask.h"

#include "config.h"

#define LANDING_MSG "landing"
#define TAKEOFF_MSG "takeoff"

HangarControlTask::HangarControlTask(HWPlatform *hw, MsgService *serial,
                                     Context *context)
    : hw(hw), serial(serial), context(context) {
}

HangarControlTask::HangarControlTask(HWPlatform *hw, MsgService *serial,
                                     Context *context, int period)
    : HangarControlTask(hw, serial, context) {
    this->init(period);
}

void HangarControlTask::init(int period) {
    Task::init(period);
    this->state = NORMAL;
    this->serial->sendMsg("normal");
}

void HangarControlTask::tick() {
    switch (this->state) {
        case NORMAL:
            this->serial->sendMsg(this->serial->getMsg());
            this->serial->sendMsg("rest");
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
