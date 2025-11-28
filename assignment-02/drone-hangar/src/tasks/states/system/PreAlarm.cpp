#include "tasks/states/system/PreAlarm.h"

#include "tasks/SystemTask.h"

#include "parameters.h"

static unsigned long timer;

void PreAlarm::onEnter(SystemTask &task, HWSystem &hw, Context &ctx, MsgService &msg) {
    msg.send(PREALARM_STATE_MSG);
    timer = millis();
}

void PreAlarm::onExit(SystemTask &task, HWSystem &hw, Context &ctx, MsgService &msg) {
}

void PreAlarm::tick(SystemTask &task, HWSystem &hw, Context &ctx, MsgService &msg) {
    if (hw.temperature() > TEMP2) {
        if (millis() - timer >= T2) {
            task.changeState(new ::PreAlarm);
        }
    } else {
        timer = millis();
    }
}
