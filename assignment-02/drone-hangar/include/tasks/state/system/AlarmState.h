#pragma once

#include "tasks/state/system/SystemState.h"

class AlarmState : public SystemState {
  public:
    AlarmState();

    void onEnter(SystemTask *sys, HWPlatform *hw, Context *cxt);

    void onExit(SystemTask *sys, HWPlatform *hw, Context *cxt);

    void tick(SystemTask *sys, HWPlatform *hw, Context *cxt);

    ~AlarmState() = default;
};