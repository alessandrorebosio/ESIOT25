#pragma once

#include "tasks/states/flight/FlightState.h"

namespace Flight {

class Operating final : public FlightState {
  public:
    void onEnter(FlightTask &task, HWFlight &hw, Context &ctx, const bool &enabled);

    void onExit(FlightTask &task, HWFlight &hw, Context &ctx, const bool &enabled);

    void tick(FlightTask &task, HWFlight &hw, Context &ctx, const bool &enabled);

    ~Operating() = default;
};

} // namespace Flight
