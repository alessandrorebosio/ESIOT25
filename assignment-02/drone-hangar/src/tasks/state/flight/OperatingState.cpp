#include "tasks/state/flight/OperatingState.h"
#include "tasks/state/flight/WaitingState.h"

#include "tasks/FlightTask.h"

OperatingState::OperatingState() {
}

void OperatingState::onEnter(FlightTask *fl, HWPlatform *hw, Context *cxt) {
    hw->serial()->sendMsg(hw->serial()->getMsg());
    cxt->startMeasuring();
    cxt->startBlink();
    cxt->openGate();
}

void OperatingState::onExit(FlightTask *fl, HWPlatform *hw, Context *cxt) {
}

void OperatingState::tick(FlightTask *fl, HWPlatform *hw, Context *cxt) {
    if (cxt->isMeasured()) {
        fl->changeState(new ::WaitingState);
    }
}
