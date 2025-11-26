#include "tasks/state/check/OutsideState.h"
#include "tasks/state/check/InsideState.h"

#include "tasks/CheckTask.h"

OutsideState::OutsideState() {
}

void OutsideState::onEnter(CheckTask *chk, HWPlatform *hw, Context *cxt) {
    hw->serial()->sendMsg("outside");
}

void OutsideState::onExit(CheckTask *chk, HWPlatform *hw, Context *cxt) {
}

void OutsideState::tick(CheckTask *chk, HWPlatform *hw, Context *cxt) {
}