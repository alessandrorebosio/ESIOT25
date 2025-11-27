#pragma once

#include "tasks/states/system/SystemState.h"

class Alarm final : public SystemState {
  public:
    void onEnter(SystemTask &task, HWSystem &hw, Context &cxt);

    void onExit(SystemTask &task, HWSystem &hw, Context &cxt);

    void tick(SystemTask &task, HWSystem &hw, Context &cxt);

    ~Alarm() = default;
};
