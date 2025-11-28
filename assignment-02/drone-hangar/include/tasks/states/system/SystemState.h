#pragma once

namespace System {
class SystemTask;
}

class HWSystem;
class Context;
class MsgService;

namespace System {

class SystemState {
  public:
    virtual void onEnter(SystemTask &task, HWSystem &hw, Context &ctx, MsgService &msg) = 0;

    virtual void onExit(SystemTask &task, HWSystem &hw, Context &ctx, MsgService &msg) = 0;

    virtual void tick(SystemTask &task, HWSystem &hw, Context &ctx, MsgService &msg) = 0;

    virtual ~SystemState() = default;
};

} // namespace System
