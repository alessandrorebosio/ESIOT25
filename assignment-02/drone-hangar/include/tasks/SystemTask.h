#pragma once

#include "core/Context.h"
#include "core/MsgService.h"

#include "model/system/HWSystem.h"

#include "tasks/states/system/SystemState.h"

#include "Task.h"

namespace System {

class SystemTask final : public Task {
  private:
    HWSystem *hardware;
    Context &context;
    MsgService &msg;
    SystemState *state;

  public:
    explicit SystemTask(HWSystem *hw, Context &ctx, MsgService &msg, int period);

    void tick() override;

    void changeState(SystemState *newState);

    ~SystemTask();
};

} // namespace System
