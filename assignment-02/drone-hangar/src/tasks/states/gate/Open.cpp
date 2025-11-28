#include "tasks/states/gate/Open.h"
#include "tasks/states/gate/Closing.h"

#include "tasks/GateTask.h"

namespace Gate {

void Open::onEnter(GateTask &task, HWGate &hw, const bool &enabled) {
    hw.motorOff();
}

void Open::onExit(GateTask &task, HWGate &hw, const bool &enabled) {
    hw.motorOn();
}

void Open::tick(GateTask &task, HWGate &hw, const bool &enabled) {
    if (!enabled) {
        task.changeState(new Closing);
    }
}

} // namespace Gate
