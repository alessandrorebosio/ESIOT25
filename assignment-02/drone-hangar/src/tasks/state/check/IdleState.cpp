#include "tasks/state/check/IdleState.h"
#include "tasks/state/check/MeasuringState.h"

#include "tasks/CheckTask.h"

IdleState::IdleState() {
}

void IdleState::onEnter(CheckTask *chk, HWPlatform *hw, Context *cxt) {
    hw->serial()->sendMsg("idle");
}

void IdleState::onExit(CheckTask *chk, HWPlatform *hw, Context *cxt) {
}

void IdleState::tick(CheckTask *chk, HWPlatform *hw, Context *cxt) {
    // if (cxt->shouldMeasure()) {
    //     chk->changeState(new ::MeasuringState);
    // }
        chk->changeState(new ::MeasuringState);

}