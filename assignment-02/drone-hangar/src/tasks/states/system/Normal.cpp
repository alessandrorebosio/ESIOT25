#include "tasks/states/system/Normal.h"
#include "tasks/states/system/PreAlarm.h"

#include "tasks/SystemTask.h"

#define TEMP1 25
#define T1 10000

static unsigned long timer;

void Normal::onEnter(SystemTask &task, HWSystem &hw, Context &cxt, MsgService &msg) {
    msg.send("normal");
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
