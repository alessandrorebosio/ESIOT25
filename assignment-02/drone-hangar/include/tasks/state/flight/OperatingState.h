#pragma once

#include "tasks/state/flight/FlightState.h"

class OperatingState : public FlightState {
  public:
    OperatingState();

    void onEnter(FlightTask *fl, HWPlatform *hw, Context *cxt);

    void onExit(FlightTask *fl, HWPlatform *hw, Context *cxt);

    void tick(FlightTask *fl, HWPlatform *hw, Context *cxt);

    ~OperatingState() = default;
};
