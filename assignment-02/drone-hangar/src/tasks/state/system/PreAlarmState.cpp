#include "tasks/state/system/PreAlarmState.h"
#include "tasks/SystemTask.h"
#include "tasks/state/system/AlarmState.h"

PreAlarmState::PreAlarmState() {
}

void PreAlarmState::onEnter(SystemTask *sys, HWPlatform *hw, Context *ctx) {
    hw->serial()->sendMsg("prealarm");
}

void PreAlarmState::onExit(SystemTask *sys, HWPlatform *hw, Context *ctx) {
}

void PreAlarmState::tick(SystemTask *sys, HWPlatform *hw, Context *ctx) {
    sys->changeState(new ::AlarmState);
}
