#pragma once

#include "devices/Motor.h"
#include "model/Context.h"

#include "Task.h"

class SweepingTask : public Task {
  private:
    Motor *motor;
    Context *context;
    enum State { OPEN, CLOSE, OPENING, CLOSING } state;

    long stateStartTime;

    void setState(State s);
    inline long elapsedTime();

  public:
    explicit SweepingTask(Motor *motor, Context *context);
    explicit SweepingTask(Motor *motor, Context *context, int period);

    void init(int period);
    void reset();
    void tick();
};
