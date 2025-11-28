#include "tasks/states/gate/Closing.h"
#include "tasks/states/gate/Close.h"
#include "tasks/states/gate/Opening.h"

#include "tasks/GateTask.h"

#include "parameters.h"

static unsigned long timer;

namespace Gate {

void Closing::onEnter(GateTask &task, Motor &motor, const bool &enabled) {
    timer = millis();
}

void Closing::onExit(GateTask &task, Motor &motor, const bool &enabled) {
}

void Closing::tick(GateTask &task, Motor &motor, const bool &enabled) {
    if (enabled) {
        task.changeState(new Opening);
    }

    unsigned long dt = millis() - timer;
    short pos = OPEN_POS - ((float)dt / CLOSE_TIME) * OPEN_POS;

    motor.setPosition(pos);

    if (dt >= CLOSE_TIME) {
        motor.setPosition(CLOSE_POS);
        task.changeState(new Close);
    }
}

} // namespace Gate
