#pragma once

#include "tasks/states/gate/GateState.h"

namespace Gate {

class Open final : public GateState {
  public:
    void onEnter(GateTask &task, Motor &motor, const bool &enabled);

    void onExit(GateTask &task, Motor &motor, const bool &enabled);

    void tick(GateTask &task, Motor &motor, const bool &enabled);

    ~Open() = default;
};

} // namespace Gate
