#pragma once

#include "core/Context.h"
#include "core/MsgService.h"

#include "model/flight/HWFlight.h"
#include "tasks/states/flight/FlightState.h"

#include "Task.h"

namespace Flight {
class FlightTask final : public Task {
  private:
    HWFlight hardware;
    Context &context;
    MsgService &msg;
    const bool &enabled;
    FlightState *state;

  public:
    explicit FlightTask(Pir &pir, Sonar &sonar, TMP36 &temp, Context &ctx, MsgService &msg, const bool &enabled, int period);

    void tick() override;

    void changeState(FlightState *newState);

    ~FlightTask();
};
} // namespace Flight
