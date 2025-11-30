#pragma once

#include "Task.h"
#include "core/Context.h"
#include "model/landing/HWLanding.h"
#include "tasks/states/landing/LandingState.h"

namespace Landing {

class LandingTask final : public Task {
  private:
    HWLanding *hardware;
    Context &context;
    const bool &enabled;
    LandingState *state;

  public:
    explicit LandingTask(HWLanding *hw, Context &ctx, const bool &enabled, int period);

    void tick() override;

    void changeState(LandingState *newState);

    /**
     * @brief Destroy the Landing Task object
     */
    ~LandingTask() = default;
};

} // namespace Landing
