#include "tasks/state/check/IdleState.h"
#include "tasks/state/check/MeasuringState.h"

#include "tasks/CheckTask.h"

IdleState::IdleState() {
}

void IdleState::onEnter(CheckTask *chk, HWPlatform *hw, Context *ctx) {
    hw->serial()->sendMsg("idle");
}

void IdleState::onExit(CheckTask *chk, HWPlatform *hw, Context *ctx) {
}

void IdleState::tick(CheckTask *chk, HWPlatform *hw, Context *ctx) {
    if (ctx->shouldMeasure()) {
        chk->changeState(new ::MeasuringState);
    }
}
