#pragma once

namespace Flight {
class FlightTask;
}

class HWFlight;
class Context;

namespace Flight {

class FlightState {
  public:
    virtual void onEnter(FlightTask &task, HWFlight &hw, Context &ctx, const bool &enabled) = 0;

    virtual void onExit(FlightTask &task, HWFlight &hw, Context &ctx, const bool &enabled) = 0;

    virtual void tick(FlightTask &task, HWFlight &hw, Context &ctx, const bool &enabled) = 0;

    virtual ~FlightState() = default;
};

} // namespace Flight
