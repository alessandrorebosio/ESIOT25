#pragma once

#include "model/Context.h"
#include "model/HWPlatform.h"

class BlinkingTask;

class BlinkingState {
  public:
    virtual void onEnter(BlinkingTask *bln, HWPlatform *hw, Context *cxt) = 0;

    virtual void onExit(BlinkingTask *bln, HWPlatform *hw, Context *cxt) = 0;

    virtual void tick(BlinkingTask *bln, HWPlatform *hw, Context *cxt) = 0;

    virtual ~BlinkingState() = default;
};
