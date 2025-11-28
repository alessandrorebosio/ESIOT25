#include "tasks/states/gate/Opening.h"
#include "tasks/states/gate/Closing.h"
#include "tasks/states/gate/Open.h"

#include "tasks/GateTask.h"

#include "parameters.h"

static unsigned long timer;

void Opening::onEnter(GateTask &task, Motor &motor, const bool &enabled) {
    timer = millis();
}

void Opening::onExit(GateTask &task, Motor &motor, const bool &enabled) {
}

void Opening::tick(GateTask &task, Motor &motor, const bool &enabled) {
    if (!enabled) {
        task.changeState(new ::Closing);
    }

    unsigned long dt = millis() - timer;
    short pos = ((float)dt / OPEN_TIME) * OPEN_POS;

    motor.setPosition(pos);

    if (dt >= OPEN_TIME) {
        motor.setPosition(OPEN_POS);
        task.changeState(new ::Open);
    }
}
