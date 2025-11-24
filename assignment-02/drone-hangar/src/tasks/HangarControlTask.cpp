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
}

void HangarControlTask::tick() {
    switch (this->state) {
        case NORMAL:
            // TODO: led offs + closeDoor

            if (this->msg->isMsgAvailable()) {
                String msg = this->msg->getMsg();
                if (msg == TAKEOFF_MSG ||
                    (msg == LANDING_MSG && this->hw->isDetected())) {
                    this->setState(OPERATING);
                }
            }

            if (this->hw->isOverTemperature(TEMP1)) {
                this->setState(PREALARM);
            }
            break;

        case OPERATING:
            // TODO: openDoor + blinking

            if (this->hw->isOverDistance(D1) || !this->hw->isOverDistance(D2)) {
                this->setState(WAITING); // can we have problem
            }
            break;

        case WAITING:
            if (this->elapsedTime(T1) && this->hw->isOverDistance(D1)) {
                this->hw->printOnLcd("OUTSIDE");
                this->state = NORMAL;
            } else if (this->elapsedTime(T2) && !this->hw->isOverDistance(D2)) {
                this->hw->printOnLcd("INSIDE");
                this->state = NORMAL;
            } else {
                this->setState(OPERATING);
            }

            break;

        case PREALARM:
            if (this->elapsedTime(T4) && this->hw->isOverTemperature(TEMP2)) {
                this->setState(ALARM);
            } else {
                this->setState(NORMAL);
            }
            break;

        case ALARM:
            // TODO: doorClose + L3 ON
            if (this->hw->isPressed()) {
                this->setState(NORMAL);
                this->hw->turnLedOffs();
            }
            break;
    }
}

void HangarControlTask::setState(State s) {
    this->hw->printOnLcd(toString(s));
    this->msg->sendMsg(toString(s));
    this->state = s;
    this->stateStartTime = millis();
}

inline bool HangarControlTask::elapsedTime(unsigned long time) {
    return (unsigned long)(millis() - this->stateStartTime) > time;
}
