#pragma once

#include "core/Context.h"
#include "model/HWPlatform.h"

#include "tasks/state/flight/FlightState.h"

#include "Task.h"

class FlightTask final : public Task {
  private:
    HWPlatform *hw;
    Context *context;
    FlightState *state;

  public:
    explicit FlightTask(HWPlatform *hw, Context *context);

    explicit FlightTask(HWPlatform *hw, Context *context, int period);

    void init(int period);

    void tick();

    void changeState(FlightState *state) {
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
