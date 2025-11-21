#include "tasks/HangarControlTask.h"

#include "model/state/Outside.h"
#include "model/state/Takeoff.h"

#define LANDING_MSG "landing"
#define TAKEOFF_MSG "takeoff"

void HangarControlTask::init(const int period) {
    Task::init(period);
    this->state = WAITING;
}

void HangarControlTask::tick() {
    switch (this->state) {
        case WAITING:
            if (this->serialMonitor->isMsgAvailable()) {
                String msg = this->serialMonitor->getMsg();
                if (msg == LANDING_MSG) {
                    this->hw->changeState(new ::Outside);
                }
                if (msg == TAKEOFF_MSG) {
                    this->hw->changeState(new ::Takeoff);
                }
            }

            if (this->hw->getTemperature() > 50) {
                this->hw->changeState(NULL);
            }
            break;
    }
}
