#pragma once

#include <Motor.h>

#include "tasks/states/gate/GateState.h"

#include "Task.h"

class GateTask final : public Task {
  private:
    Motor &motor;
    const bool &enabled;
    int currentAngle;
    GateState *state;

  public:
    explicit GateTask(Motor &motor, const bool &enabled, int period);

    void tick() override;

    void changeState(GateState *newState);

    ~GateTask();
};
