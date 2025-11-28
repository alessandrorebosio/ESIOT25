#pragma once

#include "tasks/states/blink/BlinkState.h"

namespace Blink {

class Off final : public BlinkState {
  public:
    void onEnter(BlinkTask &task, HWBlink &hw, const bool &enabled);

    void onExit(BlinkTask &task, HWBlink &hw, const bool &enabled);

    void tick(BlinkTask &task, HWBlink &hw, const bool &enabled);

    ~Off() = default;
};

} // namespace Blink
