#pragma once

#include "Task.h"
#include "core/Context.h"
#include "model/takeoff/HWTakeOff.h"
#include "tasks/states/takeoff/TakeOffState.h"

namespace TakeOff {

class TakeOffTask final : public Task {
  private:
    HWTakeOff *hardware;
    Context &context;
    const bool &enabled;
    TakeOffState *state;

  public:
    explicit TakeOffTask(HWTakeOff *hw, Context &ctx, const bool &enabled, int period);

    void tick() override;

    void changeState(TakeOffState *newState);

    /**
     * @brief Destroy the Landing Task object
     */
    ~TakeOffTask() = default;
};

} // namespace Landing
