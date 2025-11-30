#pragma once

#include "tasks/states/landing/LandingState.h"

namespace Landing {

class Measuring : public LandingState {
  private:
    unsigned long timer;

  public:
    void onEnter(LandingTask &task, HWLanding &hw, Context &ctx, const bool &enabled);

    void onExit(LandingTask &task, HWLanding &hw, Context &ctx, const bool &enabled);

    void tick(LandingTask &task, HWLanding &hw, Context &ctx, const bool &enabled);

    ~Measuring() = default;
};

} // namespace Landing
