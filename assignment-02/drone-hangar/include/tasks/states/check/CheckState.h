#pragma once

namespace Check {
class CheckTask;
}

class HWCheck;
class Context;
class MsgService;

namespace Check {

class CheckState {
  public:
    virtual void onEnter(CheckTask &task, HWCheck &hw, Context &ctx, const bool &enabled) = 0;

    virtual void onExit(CheckTask &task, HWCheck &hw, Context &ctx, const bool &enabled) = 0;

    virtual void tick(CheckTask &task, HWCheck &hw, Context &ctx, const bool &enabled) = 0;

    virtual ~CheckState() = default;
};

} // namespace Check
