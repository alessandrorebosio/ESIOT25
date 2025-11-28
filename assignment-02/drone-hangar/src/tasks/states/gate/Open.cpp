#include "tasks/states/gate/Open.h"
#include "tasks/states/gate/Closing.h"

#include "tasks/GateTask.h"

namespace Gate {

void Open::onEnter(GateTask &task, Motor &motor, const bool &enabled) {
    motor.off();
}

void Open::onExit(GateTask &task, Motor &motor, const bool &enabled) {
    motor.on();
}

void Open::tick(GateTask &task, Motor &motor, const bool &enabled) {
    if (!enabled) {
        task.changeState(new Closing);
    }
}

} // namespace Gate
