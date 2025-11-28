#pragma once

#include "tasks/states/gate/GateState.h"

namespace Gate {

class Opening final : public GateState {
  public:
    void onEnter(GateTask &task, HWGate &hw, const bool &enabled);

    void onExit(GateTask &task, HWGate &hw, const bool &enabled);

    void tick(GateTask &task, HWGate &hw, const bool &enabled);

    ~Opening() = default;
};

} // namespace Gate
