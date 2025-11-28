#pragma once

namespace Gate {
class GateTask;
}

class HWGate;

namespace Gate {

class GateState {
  public:
    virtual void onEnter(GateTask &task, HWGate &hw, const bool &enabled) = 0;

    virtual void onExit(GateTask &task, HWGate &hw, const bool &enabled) = 0;

    virtual void tick(GateTask &task, HWGate &hw, const bool &enabled) = 0;

    virtual ~GateState() = default;
};

} // namespace Gate
