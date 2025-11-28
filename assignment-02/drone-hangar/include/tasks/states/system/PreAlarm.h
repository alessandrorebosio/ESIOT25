#pragma once

#include "tasks/states/system/SystemState.h"

class PreAlarm final : public SystemState {
  public:
    void onEnter(SystemTask &task, HWSystem &hw, Context &cxt, MsgService &msg);

    void onExit(SystemTask &task, HWSystem &hw, Context &cxt, MsgService &msg);

    void tick(SystemTask &task, HWSystem &hw, Context &cxt, MsgService &msg);

    ~PreAlarm() = default;
};
