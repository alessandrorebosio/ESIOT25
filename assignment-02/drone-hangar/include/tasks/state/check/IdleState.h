#pragma once

#include "tasks/state/check/CheckState.h"

class IdleState : public CheckState {
  public:
    IdleState();

    void onEnter(CheckTask *chk, HWPlatform *hw, Context *ctx);

    void onExit(CheckTask *chk, HWPlatform *hw, Context *ctx);

    void tick(CheckTask *chk, HWPlatform *hw, Context *ctx);

    ~IdleState() = default;
};