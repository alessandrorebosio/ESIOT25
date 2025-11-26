#include "tasks/state/system/AlarmState.h"
#include "tasks/SystemTask.h"
#include "tasks/state/system/NormalState.h"

AlarmState::AlarmState() {
}

void AlarmState::onEnter(SystemTask *sys, HWPlatform *hw, Context *ctx) {
    hw->serial()->sendMsg("alarm");
    hw->turnOnL3();
}

void AlarmState::onExit(SystemTask *sys, HWPlatform *hw, Context *ctx) {
    hw->turnOffL3();
}

void AlarmState::tick(SystemTask *sys, HWPlatform *hw, Context *ctx) {
    if (hw->isPressed()) {
        sys->changeState(new ::NormalState);
    }
}
