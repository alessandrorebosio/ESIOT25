#include "tasks/state/check/IdleState.h"
#include "tasks/state/check/OutsideState.h"
#include "tasks/state/check/InsideState.h"

#include "tasks/CheckTask.h"

IdleState::IdleState() {
}

void IdleState::onEnter(CheckTask *chk, HWPlatform *hw, Context *cxt) {
}

void IdleState::onExit(CheckTask *chk, HWPlatform *hw, Context *cxt) {
}

void IdleState::tick(CheckTask *chk, HWPlatform *hw, Context *cxt) {
    if (hw->isOverDistance1()) {
        chk->changeState(new ::OutsideState);
    } else {
        chk->changeState(new ::InsideState);
    }
}