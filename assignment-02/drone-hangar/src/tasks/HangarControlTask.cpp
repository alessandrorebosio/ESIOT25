#include "tasks/HangarControlTask.h"

#include "config.h"

#define LANDING_MSG "landing"
#define TAKEOFF_MSG "takeoff"

HangarControlTask::HangarControlTask(HWPlatform *hw, MsgService *msg,
                                     Context *context)
    : hw(hw), serial(msg), context(context) {
}

HangarControlTask::HangarControlTask(HWPlatform *hw, MsgService *msg,
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
            this->serial->sendMsg("normal");
            // this->serial->sendMsg("normal");

            if (this->serial->isMsgAvailable()) {
                this->serial->read();
            }

            if (this->serial->getMsg().equals(TAKEOFF_MSG)) {
                this->hw->printOnLcd(this->serial->getMsg());
                this->serial->sendMsg("DRONE: " + this->serial->getMsg());
                this->serial->clear();
                this->state = OPERATING;
            }

            if (this->hw->isOverTemperature(TEMP1)) {
                this->serial->sendMsg("prealarm");
                this->state = PREALARM;
            }
            break;

        case OPERATING:
            break;

        case WAITING:
            break;

        case PREALARM:
            this->serial->sendMsg(String(freeRAM()));
            break;

        case ALARM:
            if (this->hw->isPressed()) {
                this->serial->sendMsg("ok");
            }
            break;
    }
}

int HangarControlTask::freeRAM() {
    extern int __heap_start, *__brkval;
    int v;
    return (int)&v - ((__brkval == 0) ? (int)&__heap_start : (int)__brkval);
}
