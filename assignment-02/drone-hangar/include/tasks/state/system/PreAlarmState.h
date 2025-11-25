#pragma once

#include "tasks/state/system/SystemState.h"

class PreAlarmState : public SystemState {
  public:
    PreAlarmState();

    void onEnter(SystemTask *sys, HWPlatform *hw, Context *cxt);

    void onExit(SystemTask *sys, HWPlatform *hw, Context *cxt);

    void tick(SystemTask *sys, HWPlatform *hw, Context *cxt);

    ~PreAlarmState() = default;
};
