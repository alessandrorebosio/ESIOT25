#include "tasks/state/system/AlarmState.h"
#include "tasks/SystemTask.h"
#include "tasks/state/system/NormalState.h"

AlarmState::AlarmState() {
}

void AlarmState::onEnter(SystemTask *sys, HWPlatform *hw, Context *ctx) {
    hw->serial()->sendMsg("alarm");
}

void AlarmState::onExit(SystemTask *sys, HWPlatform *hw, Context *ctx) {
}

void AlarmState::tick(SystemTask *sys, HWPlatform *hw, Context *ctx) {
    sys->changeState(new ::NormalState);
}