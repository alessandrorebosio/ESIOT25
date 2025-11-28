#pragma once

namespace Gate {
class GateTask;
}

class Motor;

namespace Gate {

class GateState {
  public:
    virtual void onEnter(GateTask &task, Motor &motor, const bool &enabled) = 0;

    virtual void onExit(GateTask &task, Motor &motor, const bool &enabled) = 0;

    virtual void tick(GateTask &task, Motor &motor, const bool &enabled) = 0;

    virtual ~GateState() = default;
};

} // namespace Gate
