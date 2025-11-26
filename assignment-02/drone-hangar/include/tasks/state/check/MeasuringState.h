#pragma once

#include "tasks/state/check/CheckState.h"

class MeasuringState : public CheckState {
  public:
    MeasuringState();

    void onEnter(CheckTask *chk, HWPlatform *hw, Context *cxt);

    void onExit(CheckTask *chk, HWPlatform *hw, Context *cxt);

    void tick(CheckTask *chk, HWPlatform *hw, Context *cxt);

    ~MeasuringState() = default;
};