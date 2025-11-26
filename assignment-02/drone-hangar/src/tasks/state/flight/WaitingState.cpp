#include "tasks/state/flight/WaitingState.h"
#include "tasks/state/flight/OperatingState.h"

#include "tasks/FlightTask.h"

#define TAKEOFF "takeoff"
#define LANDING "landing"

WaitingState::WaitingState() {
}

void WaitingState::onEnter(FlightTask *fl, HWPlatform *hw, Context *cxt) {
    cxt->stopBlink();
    cxt->closeGate();
}

void WaitingState::onExit(FlightTask *fl, HWPlatform *hw, Context *cxt) {
}

void WaitingState::tick(FlightTask *fl, HWPlatform *hw, Context *cxt) {
    if (hw->serial()->isMsgAvailable()) {
        hw->serial()->read();
    }

    if ((hw->msgIsEqual(TAKEOFF) && !hw->isOverDistance1()) ||
        (hw->msgIsEqual(LANDING) && hw->isDetected())) {
        fl->changeState(new ::OperatingState);
    }
}
