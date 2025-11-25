#pragma once

#include "tasks/state/system/SystemState.h"

class NormalState : public SystemState {
  public:
    NormalState();

    void onEnter(SystemTask *sys, HWPlatform *hw, Context *cxt);

    void onExit(SystemTask *sys, HWPlatform *hw, Context *cxt);

    void tick(SystemTask *sys, HWPlatform *hw, Context *cxt);

    ~NormalState() = default;
};