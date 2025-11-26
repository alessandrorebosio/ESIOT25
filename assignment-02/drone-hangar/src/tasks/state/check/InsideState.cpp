#include "tasks/state/check/InsideState.h"
#include "tasks/state/check/OutsideState.h"

#include "tasks/CheckTask.h"

InsideState::InsideState(){
}

void InsideState::onEnter(CheckTask *chk, HWPlatform *hw, Context *cxt) {
    hw->serial()->sendMsg("inside");
}

void InsideState::onExit(CheckTask *chk, HWPlatform *hw, Context *cxt) {
}

void InsideState::tick(CheckTask *chk, HWPlatform *hw, Context *cxt) {
}