#pragma once

#include "tasks/states/operating/OperatingState.h"

namespace Operating {

class Measuring : public OperatingState {
  private:
    unsigned long takeOffTimer;
    unsigned long landingTimer;

  public:
    void onEnter(OperatingTask &task, HWOperating &hw, Context &ctx);

    void onExit(OperatingTask &task, HWOperating &hw, Context &ctx);

    void tick(OperatingTask &task, HWOperating &hw, Context &ctx);

    ~Measuring() = default;
};

} // namespace Operating
