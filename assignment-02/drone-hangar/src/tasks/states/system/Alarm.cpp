#include "tasks/states/system/Alarm.h"
#include "tasks/states/system/Normal.h"

#include "tasks/SystemTask.h"

#include "parameters.h"

namespace System {

void Alarm::onEnter(SystemTask &task, HWSystem &hw, Context &ctx, MsgService &msg) {
    msg.send(ALARM_STATE_MSG);
    ctx.startBlink();
}

void Alarm::onExit(SystemTask &task, HWSystem &hw, Context &ctx, MsgService &msg) {
    ctx.stopBlink();
}

void Alarm::tick(SystemTask &task, HWSystem &hw, Context &ctx, MsgService &msg) {
    if (hw.isPressed()) {
        task.changeState(new Normal);
    }
}

} // namespace System
