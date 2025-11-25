#pragma once

#include "model/Context.h"
#include "model/HWPlatform.h"
#include "tasks/state/system/SystemState.h"

#include "Task.h"

class SystemTask final : public Task {
  private:
    HWPlatform *hw;
    Context *context;
    SystemState *state;

  public:
    explicit SystemTask(HWPlatform *hw, Context *context);

    explicit SystemTask(HWPlatform *hw, Context *context, int period);

    void init(int period);

    void tick();

    void changeState(SystemState *state) {
        if (this->state) {
            this->state->onExit(this, hw, context);
            delete this->state;
        }
        this->state = state;
        if (this->state) {
            this->state->onEnter(this, hw, context);
        }
    }
};
