#pragma once

#include "tasks/state/check/CheckState.h"

class OutsideState : public CheckState {
  public:
    OutsideState();

    void onEnter(CheckTask *chk, HWPlatform *hw, Context *cxt);

    void onExit(CheckTask *chk, HWPlatform *hw, Context *cxt);

    void tick(CheckTask *chk, HWPlatform *hw, Context *cxt);

    ~OutsideState() = default;
};