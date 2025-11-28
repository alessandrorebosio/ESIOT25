#include "tasks/CheckTask.h"

#include "tasks/states/check/Idle.h"
#include "tasks/states/check/Measuring.h"

void Idle::onEnter(CheckTask &task, HWCheck &hw, Context &ctx, MsgService &msg, const bool &enabled) {
}

void Idle::onExit(CheckTask &task, HWCheck &hw, Context &ctx, MsgService &msg, const bool &enabled) {
}

void Idle::tick(CheckTask &task, HWCheck &hw, Context &ctx, MsgService &msg, const bool &enabled) {
    if (enabled) {
        task.changeState(new ::Measuring);
    }
}
