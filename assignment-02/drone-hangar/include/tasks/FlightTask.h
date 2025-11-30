#pragma once

#include "core/Context.h"
#include "model/flight/HWFlight.h"
#include "tasks/states/flight/FlightState.h"

#include "Task.h"

namespace Flight {

class FlightTask final : public Task {
  private:
    HWFlight *hardware;
    Context &context;
    const bool &enabled;
    FlightState *state;

    FlightState *initialState(void);

  public:
    explicit FlightTask(HWFlight *hw, Context &ctx, const bool &enabled, int period);

    void tick() override;

    void changeState(FlightState *newState);

    ~FlightTask();
};

} // namespace Flight
