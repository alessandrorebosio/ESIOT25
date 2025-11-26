#pragma once

#include "core/Context.h"
#include "model/HWPlatform.h"

class CheckTask;

class CheckState {
  public:
    virtual void onEnter(CheckTask *chk, HWPlatform *hw, Context *cxt) = 0;

    virtual void onExit(CheckTask *chk, HWPlatform *hw, Context *cxt) = 0;

    virtual void tick(CheckTask *chk, HWPlatform *hw, Context *cxt) = 0;

    virtual ~CheckState() = default;
};
