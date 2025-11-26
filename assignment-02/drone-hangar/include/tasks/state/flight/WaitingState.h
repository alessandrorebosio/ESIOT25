#pragma once

#include "tasks/state/flight/FlightState.h"

class WaitingState : public FlightState {
  public:
    WaitingState();

    void onEnter(FlightTask *fl, HWPlatform *hw, Context *cxt);

    void onExit(FlightTask *fl, HWPlatform *hw, Context *cxt);

    void tick(FlightTask *fl, HWPlatform *hw, Context *cxt);

    ~WaitingState() = default;
};
