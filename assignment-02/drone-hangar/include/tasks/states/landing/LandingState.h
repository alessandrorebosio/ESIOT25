#pragma once

class HWLanding;
class Context;

namespace Landing {

class LandingTask;

class LandingState {
  public:
    virtual void onEnter(LandingTask &task, HWLanding &hw, Context &ctx, const bool &enabled) = 0;

    virtual void onExit(LandingTask &task, HWLanding &hw, Context &ctx, const bool &enabled) = 0;

    virtual void tick(LandingTask &task, HWLanding &hw, Context &ctx, const bool &enabled) = 0;

    virtual ~LandingState() = default;
};

} // namespace Landing
