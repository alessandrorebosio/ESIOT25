#include "tasks/state/flight/WaitingState.h"
#include "tasks/state/flight/OperatingState.h"

#include "tasks/FlightTask.h"

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

    String msg = hw->serial()->getMsg();
    if (msg == "takeoff" || msg == "landing") {
        fl->changeState(new ::OperatingState);
    }
}
