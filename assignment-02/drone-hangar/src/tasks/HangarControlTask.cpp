#include "tasks/HangarControlTask.h"

#define LANDING_MSG "landing"
#define TAKEOFF_MSG "takeoff"

HangarControlTask::HangarControlTask(HWPlatform *hw, MsgSerivce *msg)
    : hw(hw), msg(msg) {
}

HangarControlTask::HangarControlTask(HWPlatform *hw, MsgSerivce *msg,
                                     int period)
    : HangarControlTask(hw, msg) {
    this->init(period);
}

void HangarControlTask::init(int period) {
    Task::init(period);
    this->state = NORMAL;
}

void HangarControlTask::tick() {
    switch (this->state) {
        case NORMAL:
            // TODO: led offs + closeDoor
            if (this->msg->isMsgAvailable()) {
                String msg = this->msg->getMsg();
                if (msg == LANDING_MSG || msg == TAKEOFF_MSG) {
                    this->state = MANAGE;
                }
            }

            // TODO: if after T3 [temp > temp1] set PREALARM
            break;

        case MANAGE:
            // TODO: openDoor + blinking at the end set NORMAL
            break;

        case PREALARM:
            // TODO: if after T4 if [temp > temp2] set ALARM else NORMAL
            break;

        case ALARM:
            // TODO: doorClose + L3 ON
            if (this->hw->isPressed()) {
                this->state = NORMAL;
                // TODO: turn off L3
            }
            break;
    }
}
