#pragma once

#include "tasks/states/system/SystemState.h"

class PreAlarm final : public SystemState {
  public:
    void onEnter(SystemTask &task, HWSystem &hw, Context &cxt);

    void onExit(SystemTask &task, HWSystem &hw, Context &cxt);

    void tick(SystemTask &task, HWSystem &hw, Context &cxt);

    ~PreAlarm() = default;
};
