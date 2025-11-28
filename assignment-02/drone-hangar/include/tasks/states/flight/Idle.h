#pragma once

#include "tasks/states/flight/FlightState.h"

class Idle final : public FlightState {
  public:
    void onEnter(FlightTask &task, HWFlight &hw, Context &cxt, MsgService &msg, const bool &enabled);

    void onExit(FlightTask &task, HWFlight &hw, Context &cxt, MsgService &msg, const bool &enabled);

    void tick(FlightTask &task, HWFlight &hw, Context &cxt, MsgService &msg, const bool &enabled);

    ~Idle() = default;
};
