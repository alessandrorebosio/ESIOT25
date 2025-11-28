#pragma once

#include "tasks/states/flight/FlightState.h"

namespace Flight {

class Waiting final : public FlightState {
  public:
    void onEnter(FlightTask &task, HWFlight &hw, Context &ctx, MsgService &msg, const bool &enabled);

    void onExit(FlightTask &task, HWFlight &hw, Context &ctx, MsgService &msg, const bool &enabled);

    void tick(FlightTask &task, HWFlight &hw, Context &ctx, MsgService &msg, const bool &enabled);

    ~Waiting() = default;
};

} // namespace Flight
