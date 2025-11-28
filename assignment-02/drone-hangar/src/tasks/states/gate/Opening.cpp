#include "tasks/states/gate/Opening.h"
#include "tasks/states/gate/Closing.h"
#include "tasks/states/gate/Open.h"

#include "tasks/GateTask.h"

#include "parameters.h"

static unsigned long timer;

namespace Gate {

void Opening::onEnter(GateTask &task, HWGate &hw, const bool &enabled) {
    timer = millis();
}

void Opening::onExit(GateTask &task, HWGate &hw, const bool &enabled) {
}

void Opening::tick(GateTask &task, HWGate &hw, const bool &enabled) {
    if (!enabled) {
        task.changeState(new Closing);
    }

    unsigned long dt = millis() - timer;
    short pos = ((float)dt / OPEN_TIME) * OPEN_POS;

    hw.setPosition(pos);

    if (dt >= OPEN_TIME) {
        hw.setPosition(OPEN_POS);
        task.changeState(new Open);
    }
}

} // namespace Gate
