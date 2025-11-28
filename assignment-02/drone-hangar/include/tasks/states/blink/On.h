#pragma once

#include "tasks/states/blink/BlinkState.h"

namespace Blink {

class On final : public BlinkState {
  public:
    void onEnter(BlinkTask &task, Led &led, const bool &enabled);

    void onExit(BlinkTask &task, Led &led, const bool &enabled);

    void tick(BlinkTask &task, Led &led, const bool &enabled);

    ~On() = default;
};

} // namespace Blink
