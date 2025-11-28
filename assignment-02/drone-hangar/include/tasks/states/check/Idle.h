#pragma once

#include "tasks/states/check/CheckState.h"

namespace Check {

class Idle : public CheckState {
  public:
    void onEnter(CheckTask &task, HWCheck &hw, Context &ctx, MsgService &msg, const bool &enabled);

    void onExit(CheckTask &task, HWCheck &hw, Context &ctx, MsgService &msg, const bool &enabled);

    void tick(CheckTask &task, HWCheck &hw, Context &ctx, MsgService &msg, const bool &enabled);

    ~Idle() = default;
};

} // namespace Check
