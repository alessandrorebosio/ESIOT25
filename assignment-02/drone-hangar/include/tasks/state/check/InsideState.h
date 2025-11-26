#pragma once

#include "tasks/state/check/CheckState.h"

class InsideState : public CheckState {
  public:
    InsideState();

    void onEnter(CheckTask *chk, HWPlatform *hw, Context *cxt);

    void onExit(CheckTask *chk, HWPlatform *hw, Context *cxt);

    void tick(CheckTask *chk, HWPlatform *hw, Context *cxt);

    ~InsideState() = default;
};