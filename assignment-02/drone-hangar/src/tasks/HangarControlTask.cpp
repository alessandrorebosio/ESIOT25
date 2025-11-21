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
            if (this->hw->getTemperature() > 50) {
                this->hw->changeState(NULL);
            }
            break;
    }
}
