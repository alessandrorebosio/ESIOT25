#pragma once

#include <Led.h>

#include "tasks/states/blink/BlinkState.h"

#include "Task.h"

class BlinkTask final : public Task {
  private:
    Led &led;
    const bool &enabled;
    BlinkState *state;

  public:
    explicit BlinkTask(Led &led, const bool &enabled, int period);

    void tick() override;

    void changeState(BlinkState *newState);

    ~BlinkTask() = default;
};
