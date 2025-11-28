#include "tasks/states/gate/Close.h"
#include "tasks/states/gate/Opening.h"

#include "tasks/GateTask.h"

namespace Gate {

void Close::onEnter(GateTask &task, Motor &motor, const bool &enabled) {
    motor.off();
}

void Close::onExit(GateTask &task, Motor &motor, const bool &enabled) {
    motor.on();
}

void Close::tick(GateTask &task, Motor &motor, const bool &enabled) {
    if (enabled) {
        task.changeState(new Opening);
    }
}

} // namespace Gate
