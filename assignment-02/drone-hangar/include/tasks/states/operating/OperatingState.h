#pragma once

class HWOperating;
class Context;

namespace Operating {

class OperatingTask;

class OperatingState {
  public:
    virtual void onEnter(OperatingTask &task, HWOperating &hw, Context &ctx) = 0;

    virtual void onExit(OperatingTask &task, HWOperating &hw, Context &ctx) = 0;

    virtual void tick(OperatingTask &task, HWOperating &hw, Context &ctx) = 0;

    virtual ~OperatingState() = default;
};

} // namespace Operating
