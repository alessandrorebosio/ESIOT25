#include "tasks/states/system/Normal.h"
#include "tasks/states/system/PreAlarm.h"

#include "tasks/SystemTask.h"

#include "parameters.h"

static unsigned long timer;

void Normal::onEnter(SystemTask &task, HWSystem &hw, Context &cxt, MsgService &msg) {
    msg.send(NORMAL_STATE_MSG);
    hw.turnOnLed();
    cxt.allowFlight();
    timer = millis();
}

void Normal::onExit(SystemTask &task, HWSystem &hw, Context &cxt, MsgService &msg) {
    cxt.blockFlight();
}

void Normal::tick(SystemTask &task, HWSystem &hw, Context &cxt, MsgService &msg) {
    if (hw.temperature() > TEMP1) {
        if (millis() - timer >= T1) {
            task.changeState(new ::PreAlarm);
        }
    } else {
        timer = millis();
    }
}
