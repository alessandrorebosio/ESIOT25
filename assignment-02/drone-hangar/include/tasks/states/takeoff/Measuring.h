#pragma once

#include "tasks/states/takeoff/TakeOffState.h"

namespace TakeOff {

class Measuring : public TakeOffState {
  private:
    unsigned long timer;

  public:
    void onEnter(TakeOffTask &task, HWTakeOff &hw, Context &ctx, const bool &enabled);

    void onExit(TakeOffTask &task, HWTakeOff &hw, Context &ctx, const bool &enabled);

    void tick(TakeOffTask &task, HWTakeOff &hw, Context &ctx, const bool &enabled);

    ~Measuring() = default;
};

} // namespace TakeOff
