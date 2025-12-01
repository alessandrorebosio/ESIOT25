#pragma once

#include "Task.h"
#include "core/Context.h"
#include "model/api/HWOperating.h"
#include "tasks/states/operating/OperatingState.h"

namespace Operating {

class OperatingTask final : public Task {
  private:
    HWOperating *hardware;
    Context &context;
    OperatingState *state;

  public:
    explicit OperatingTask(HWOperating *hw, Context &ctx, int period);

    void tick() override;

    void changeState(OperatingState *newState);

    /**
     * @brief Destroy the Landing Task object
     */
    ~OperatingTask();
};

} // namespace Operating
