#include "tasks/state/system/NormalState.h"
#include "tasks/SystemTask.h"
#include "tasks/state/system/PreAlarmState.h"

NormalState::NormalState() {
}

void NormalState::onEnter(SystemTask *sys, HWPlatform *hw, Context *ctx) {
    hw->serial()->sendMsg("normal");
    ctx->startBlinking();
}

void NormalState::onExit(SystemTask *sys, HWPlatform *hw, Context *ctx) {
    ctx->stopBlinking();
}

void NormalState::tick(SystemTask *sys, HWPlatform *hw, Context *ctx) {
    sys->changeState(new ::PreAlarmState);
}
