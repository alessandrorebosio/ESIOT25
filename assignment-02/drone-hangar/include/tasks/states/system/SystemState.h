#pragma once

class SystemTask;
class HWSystem;
class Context;
class MsgService;

class SystemState {
  public:
    virtual void onEnter(SystemTask &task, HWSystem &hw, Context &cxt, MsgService &msg) = 0;

    virtual void onExit(SystemTask &task, HWSystem &hw, Context &cxt, MsgService &msg) = 0;

    virtual void tick(SystemTask &task, HWSystem &hw, Context &cxt, MsgService &msg) = 0;

    virtual ~SystemState() = default;
};
