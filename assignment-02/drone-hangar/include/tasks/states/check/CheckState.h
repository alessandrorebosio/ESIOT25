#pragma once

class CheckTask;
class HWCheck;
class Context;
class MsgService;

class CheckState {
  public:
    virtual void onEnter(CheckTask &task, HWCheck &hw, Context &ctx, MsgService &msg, const bool &enabled) = 0;

    virtual void onExit(CheckTask &task, HWCheck &hw, Context &ctx, MsgService &msg, const bool &enabled) = 0;

    virtual void tick(CheckTask &task, HWCheck &hw, Context &ctx, MsgService &msg, const bool &enabled) = 0;

    virtual ~CheckState() = default;
};
