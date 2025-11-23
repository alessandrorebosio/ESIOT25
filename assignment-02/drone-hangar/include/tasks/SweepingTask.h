#pragma once

#include "tasks/Task.h"
#include "devices/Motor.h"
#include "model/Context.h"
#include <Arduino.h>

class SweepingTask : public Task {
  public:
    explicit SweepingTask(Motor *motor, Context *context);
    explicit SweepingTask(Motor *motor, Context *context, int period);

    void init(int period);
    void tick();

  private:
    Motor *motor;
    Context *context;
    enum State { CLOSED, OPENING, OPENED, CLOSING } state;

    int currentPos;
    long stateStartTime;

    void openDoor();
    void closeDoor();
    void setState(State s);
    inline long elapsedTimeInState();
};
