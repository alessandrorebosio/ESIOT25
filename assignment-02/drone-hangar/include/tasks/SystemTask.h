#pragma once

#include "model/Context.h"
#include "model/HWPlatform.h"

#include "Task.h"

class SystemTask final : public Task {
  private:
    HWPlatform *hw;
    Context *context;

    unsigned long int lastStateChange;
    enum State { NORMAL, PREALARM, ALARM } state;

    void setState(State state);

    bool elapsedTime(unsigned long int time);

  public:
    explicit SystemTask(HWPlatform *hw, Context *context);

    explicit SystemTask(HWPlatform *hw, Context *context, int period);

    void init(int period);

    void tick();
};
