#pragma once

#include <Motor.h>

#include "model/gate/HWGate.h"

#include "tasks/states/gate/GateState.h"

#include "Task.h"

namespace Gate {

class GateTask final : public Task {
  private:
    HWGate *hardware;
    const bool &enabled;
    GateState *state;

  public:
    explicit GateTask(HWGate *hw, const bool &enabled, int period);

    void tick() override;

    void changeState(GateState *newState);

    ~GateTask();
};

} // namespace Gate
