#include "tasks/state/system/NormalState.h"
#include "tasks/SystemTask.h"
#include "tasks/state/system/PreAlarmState.h"

static unsigned long timer = 0;

NormalState::NormalState() {
}

void NormalState::onEnter(SystemTask *sys, HWPlatform *hw, Context *ctx) {
    hw->serial()->sendMsg("normal");
    ctx->startBlink();
    hw->turnOnL1();
    timer = millis();
}

void NormalState::onExit(SystemTask *sys, HWPlatform *hw, Context *ctx) {
    ctx->stopBlink();
}

void NormalState::tick(SystemTask *sys, HWPlatform *hw, Context *ctx) {
    if (hw->isOverTemperature1()) {
        if (hw->expiredT1(timer)) {
            sys->changeState(new ::PreAlarmState);
        }
    } else {
        timer = millis();
    }
}
