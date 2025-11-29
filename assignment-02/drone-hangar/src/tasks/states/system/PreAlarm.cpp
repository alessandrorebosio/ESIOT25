#include "tasks/states/system/PreAlarm.h"
#include "tasks/SystemTask.h"
#include "tasks/states/system/Alarm.h"

#include "parameters.h"

static unsigned long timer;

namespace System {

void PreAlarm::onEnter(SystemTask &task, HWSystem &hw, Context &ctx) {
    ctx.printPreAlarm();
    timer = millis();
}

void PreAlarm::onExit(SystemTask &task, HWSystem &hw, Context &ctx) {
}

void PreAlarm::tick(SystemTask &task, HWSystem &hw, Context &ctx) {
    if (hw.temperature() > TEMP2) {
        if (millis() - timer >= T2) {
            task.changeState(new Alarm);
        }
    } else {
        timer = millis();
    }
}

} // namespace System
