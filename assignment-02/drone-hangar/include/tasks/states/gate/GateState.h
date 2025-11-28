#pragma once

class GateTask;
class Motor;

class GateState {
  public:
    virtual void onEnter(GateTask &task, Motor &motor, const bool &enabled) = 0;

    virtual void onExit(GateTask &task, Motor &motor, const bool &enabled) = 0;

    virtual void tick(GateTask &task, Motor &motor, const bool &enabled) = 0;

    virtual ~GateState() = default;
};
