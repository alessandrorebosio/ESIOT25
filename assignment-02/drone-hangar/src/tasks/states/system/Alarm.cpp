#include "tasks/states/system/Alarm.h"
#include "tasks/states/system/Normal.h"

#include "tasks/SystemTask.h"

void Alarm::onEnter(SystemTask &task, HWSystem &hw, Context &cxt) {
    cxt.startBlink();
}

void Alarm::onExit(SystemTask &task, HWSystem &hw, Context &cxt) {
    cxt.stopBlink();
}

void Alarm::tick(SystemTask &task, HWSystem &hw, Context &cxt) {
    if (hw.isPressed()) {
        task.changeState(new ::Normal);
    }
}
