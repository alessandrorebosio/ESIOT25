#pragma once

#include "tasks/states/takeoff/TakeOffState.h"

namespace TakeOff {

class Idle : public TakeOffState {
  public:
    void onEnter(TakeOffTask &task, HWTakeOff &hw, Context &ctx, const bool &enabled);

    void onExit(TakeOffTask &task, HWTakeOff &hw, Context &ctx, const bool &enabled);

    void tick(TakeOffTask &task, HWTakeOff &hw, Context &ctx, const bool &enabled);

    ~Idle() = default;
};

} // namespace TakeOff
