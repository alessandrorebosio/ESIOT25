#pragma once

class FlightTask;
class HWFlight;
class Context;
class MsgService;

class FlightState {
  public:
    virtual void onEnter(FlightTask &task, HWFlight &hw, Context &cxt, MsgService &msg, const bool &enabled) = 0;

    virtual void onExit(FlightTask &task, HWFlight &hw, Context &cxt, MsgService &msg, const bool &enabled) = 0;

    virtual void tick(FlightTask &task, HWFlight &hw, Context &cxt, MsgService &msg, const bool &enabled) = 0;

    virtual ~FlightState() = default;
};
