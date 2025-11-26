#pragma once

#include "tasks/state/blinking/BlinkingState.h"

class OffState : public BlinkingState {
  public:
    OffState();

    void onEnter(BlinkingTask *bln, HWPlatform *hw, Context *cxt);

    void onExit(BlinkingTask *bln, HWPlatform *hw, Context *cxt);

    void tick(BlinkingTask *bln, HWPlatform *hw, Context *cxt);

    ~OffState() = default;
};