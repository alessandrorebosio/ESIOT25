#pragma once

#include "tasks/state/blinking/BlinkingState.h"

#include "core/Context.h"
#include "model/HWPlatform.h"

#include "Task.h"

class BlinkingTask final : public Task {
  private:
    HWPlatform *hw;
    Context *context;
    BlinkingState *state;

  public:
    explicit BlinkingTask(HWPlatform *hw, Context *context);

    explicit BlinkingTask(HWPlatform *hw, Context *context, int period);

    void init(int period);

    void tick();

    void changeState(BlinkingState *state) {
        if (this->state) {
            this->state->onExit(this, hw, context);
            delete this->state;
        }
        this->state = state;
        if (this->state) {
            this->state->onEnter(this, hw, context);
        }
    }

    virtual ~BlinkingTask() = default;
};
