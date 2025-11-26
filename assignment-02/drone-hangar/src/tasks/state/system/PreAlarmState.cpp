#include "tasks/state/system/PreAlarmState.h"
#include "tasks/SystemTask.h"
#include "tasks/state/system/AlarmState.h"

static unsigned long timer = 0;

PreAlarmState::PreAlarmState() {
}

void PreAlarmState::onEnter(SystemTask *sys, HWPlatform *hw, Context *ctx) {
    hw->serial()->sendMsg("prealarm");
    timer = millis();
}

void PreAlarmState::onExit(SystemTask *sys, HWPlatform *hw, Context *ctx) {
}

void PreAlarmState::tick(SystemTask *sys, HWPlatform *hw, Context *ctx) {
    if (hw->isOverTemperature2()) {
        if (hw->expiredT2(timer)) {
            sys->changeState(new ::AlarmState);
        }
    } else {
        timer = millis();
    }
}
