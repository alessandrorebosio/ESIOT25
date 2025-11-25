#pragma once

#include "model/Context.h"
#include "model/HWPlatform.h"

class SystemTask;

class SystemState {
  public:
    virtual void onEnter(SystemTask *sys, HWPlatform *hw, Context *cxt) = 0;

    virtual void onExit(SystemTask *sys, HWPlatform *hw, Context *cxt) = 0;

    virtual void tick(SystemTask *sys, HWPlatform *hw, Context *cxt) = 0;

    virtual ~SystemState() = default;
};
