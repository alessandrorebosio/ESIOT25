#include "tasks/states/system/PreAlarm.h"

#include "tasks/SystemTask.h"

#include "parameters.h"

static unsigned long timer;

void PreAlarm::onEnter(SystemTask &task, HWSystem &hw, Context &cxt, MsgService &msg) {
    msg.send("prealarm");
    timer = millis();
}

void PreAlarm::onExit(SystemTask &task, HWSystem &hw, Context &cxt, MsgService &msg) {
}

void PreAlarm::tick(SystemTask &task, HWSystem &hw, Context &cxt, MsgService &msg) {
    if (hw.temperature() > TEMP2) {
        if (millis() - timer >= T2) {
            task.changeState(new ::PreAlarm);
        }
    } else {
        timer = millis();
    }
}
