#pragma once

#include "tasks/state/blinking/BlinkingState.h"

class OnState : public BlinkingState {
  public:
    OnState();

    void onEnter(BlinkingTask *bln, HWPlatform *hw, Context *cxt);

    void onExit(BlinkingTask *bln, HWPlatform *hw, Context *cxt);

    void tick(BlinkingTask *bln, HWPlatform *hw, Context *cxt);

    ~OnState() = default;
};