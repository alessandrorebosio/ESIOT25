#pragma once

#include "tasks/states/system/SystemState.h"

class Normal final : public SystemState {
  public:
    void onEnter(SystemTask &task, HWSystem &hw, Context &cxt);

    void onExit(SystemTask &task, HWSystem &hw, Context &cxt);

    void tick(SystemTask &task, HWSystem &hw, Context &cxt);

    ~Normal() = default;
};
