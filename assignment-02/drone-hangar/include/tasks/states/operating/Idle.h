#pragma once

#include "tasks/states/operating/OperatingState.h"

namespace Operating {

class Idle : public OperatingState {
  public:
    void onEnter(OperatingTask &task, HWOperating &hw, Context &ctx);

    void onExit(OperatingTask &task, HWOperating &hw, Context &ctx);

    void tick(OperatingTask &task, HWOperating &hw, Context &ctx);

    ~Idle() = default;
};

} // namespace Operating
