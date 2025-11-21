#pragma once

#include "Task.h"
#include "model/HWPlatform.h"

class HangarControlTask : public Task {
  private:
    HWPlatform *hw;

    enum { WAITING } state;

  public:
    HangarControlTask(HWPlatform *hw) : hw(hw) {
    }

    HangarControlTask(HWPlatform *hw, const int period)
        : HangarControlTask(hw) {
        this->init(period);
    }

    void init(int period);

    void tick();
};
