#include "tasks/states/system/PreAlarm.h"

#include "tasks/SystemTask.h"

#define TEMP2 30
#define T2 10000

static unsigned long timer;

void PreAlarm::onEnter(SystemTask &task, HWSystem &hw, Context &cxt) {
    timer = millis();
}

void PreAlarm::onExit(SystemTask &task, HWSystem &hw, Context &cxt) {
}

void PreAlarm::tick(SystemTask &task, HWSystem &hw, Context &cxt) {
    if (hw.temperature() > TEMP2) {
        if (millis() - timer >= T2) {
            task.changeState(new ::PreAlarm);
        }
    } else {
        timer = millis();
    }
}
