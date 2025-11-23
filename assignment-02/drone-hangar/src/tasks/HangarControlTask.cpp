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
                    this->hw->printOnLcd(msg);
                    this->state = MANAGE;
                }
            }

            // TODO: if after T3 [temp > temp1] set PREALARM and msg send
            // "prealarm"
            break;

        case MANAGE:
            // TODO: openDoor + blinking

            // TODO: if (d > d1 || d < d2) start count
            // TODO: after T1 or T2 set NORMAL
            // and this->hw->printOnLcd("inside" or "outside");
            // and send msg "inside or ouside"
            break;

        case PREALARM:
            // TODO: if [temp > temp2] after set ALARM and msg send
            // "alarm" else NORMAL and send msg "normal"
            break;

        case ALARM:
            // TODO: doorClose + L3 ON
            if (this->hw->isPressed()) {
                this->state = NORMAL;
                this->msg->sendMsg("normal");
                // TODO: turn off L3
            }
            break;
    }
}
