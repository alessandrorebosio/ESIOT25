#include "tasks/states/gate/Closing.h"
#include "tasks/states/gate/Close.h"

#include "tasks/GateTask.h"

#define CLOSE_TIME 2000
#define OPEN_POS 180
#define CLOSE_POS 0

static unsigned long timer;

void Closing::onEnter(GateTask &task, Motor &motor, const bool &enabled) {
    motor.on();
    timer = millis();
}

void Closing::onExit(GateTask &task, Motor &motor, const bool &enabled) {
    motor.off();
}

void Closing::tick(GateTask &task, Motor &motor, const bool &enabled) {
    unsigned long dt = millis() - timer;
    short pos = OPEN_POS - ((float)dt / CLOSE_TIME) * OPEN_POS;

    motor.setPosition(pos);

    if (dt >= CLOSE_TIME) {
        motor.setPosition(CLOSE_POS);
        task.changeState(new ::Close);
    }
}
