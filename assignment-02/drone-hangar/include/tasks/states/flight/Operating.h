#pragma once

#include "tasks/states/flight/FlightState.h"

class Operating final : public FlightState {
  public:
    void onEnter(FlightTask &task, HWFlight &hw, Context &cxt, MsgService &msg, const bool &enabled);

    void onExit(FlightTask &task, HWFlight &hw, Context &cxt, MsgService &msg, const bool &enabled);

    void tick(FlightTask &task, HWFlight &hw, Context &cxt, MsgService &msg, const bool &enabled);

    ~Operating() = default;
};
