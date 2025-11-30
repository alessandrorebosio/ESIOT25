#pragma once

#include "tasks/states/landing/LandingState.h"

namespace Landing {

class Idle : public LandingState {
  public:
    void onEnter(LandingTask &task, HWLanding &hw, Context &ctx, const bool &enabled);

    void onExit(LandingTask &task, HWLanding &hw, Context &ctx, const bool &enabled);

    void tick(LandingTask &task, HWLanding &hw, Context &ctx, const bool &enabled);

    ~Idle() = default;
};

} // namespace Landing
