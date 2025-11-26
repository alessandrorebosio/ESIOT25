#pragma once

#include "core/Context.h"
#include "model/HWPlatform.h"

class FlightTask;

class FlightState {
  public:
    virtual void onEnter(FlightTask *fl, HWPlatform *hw, Context *cxt) = 0;

    virtual void onExit(FlightTask *fl, HWPlatform *hw, Context *cxt) = 0;

    virtual void tick(FlightTask *fl, HWPlatform *hw, Context *cxt) = 0;

    virtual ~FlightState() = default;
};
