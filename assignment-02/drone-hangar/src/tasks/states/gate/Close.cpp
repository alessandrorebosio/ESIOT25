#include "tasks/states/gate/Close.h"
#include "tasks/states/gate/Opening.h"

#include "tasks/GateTask.h"

namespace Gate {

void Close::onEnter(GateTask &task, HWGate &hw, const bool &enabled) {
    hw.motorOff();
}

void Close::onExit(GateTask &task, HWGate &hw, const bool &enabled) {
    hw.motorOn();
}

void Close::tick(GateTask &task, HWGate &hw, const bool &enabled) {
    if (enabled) {
        task.changeState(new Opening);
    }
}

} // namespace Gate
