#pragma once

#include <Led.h>

#include "model/blink/HWBlink.h"

#include "tasks/states/blink/BlinkState.h"

#include "Task.h"

namespace Blink {

class BlinkTask final : public Task {
  private:
    HWBlink *hardware;
    const bool &enabled;
    BlinkState *state;

  public:
    explicit BlinkTask(HWBlink *hw, const bool &enabled, int period);

    void tick() override;

    void changeState(BlinkState *newState);

    ~BlinkTask();
};

} // namespace Blink
