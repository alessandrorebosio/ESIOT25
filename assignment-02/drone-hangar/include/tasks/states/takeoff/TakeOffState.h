#pragma once

class HWTakeOff;
class Context;

namespace TakeOff {

class TakeOffTask;

class TakeOffState {
  public:
    virtual void onEnter(TakeOffTask &task, HWTakeOff &hw, Context &ctx, const bool &enabled) = 0;

    virtual void onExit(TakeOffTask &task, HWTakeOff &hw, Context &ctx, const bool &enabled) = 0;

    virtual void tick(TakeOffTask &task, HWTakeOff &hw, Context &ctx, const bool &enabled) = 0;

    virtual ~TakeOffState() = default;
};

} // namespace Landing
