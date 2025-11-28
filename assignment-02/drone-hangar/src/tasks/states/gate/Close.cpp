#include "tasks/states/gate/Close.h"
#include "tasks/states/gate/Opening.h"

#include "tasks/GateTask.h"

void Close::onEnter(GateTask &task, Motor &motor, const bool &enabled) {
}

void Close::onExit(GateTask &task, Motor &motor, const bool &enabled) {
}

void Close::tick(GateTask &task, Motor &motor, const bool &enabled) {
    if (enabled) {
        task.changeState(new ::Opening);
    }
}
