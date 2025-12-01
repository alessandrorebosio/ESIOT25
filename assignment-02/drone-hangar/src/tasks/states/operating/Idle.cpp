#include "tasks/states/operating/Idle.h"
#include "tasks/OperatingTask.h"
#include "tasks/states/operating/Measuring.h"

namespace Operating {

void Idle::onEnter(OperatingTask &task, HWOperating &hw, Context &ctx) {
    Serial.println("idle");
}

void Idle::onExit(OperatingTask &task, HWOperating &hw, Context &ctx) {
}

void Idle::tick(OperatingTask &task, HWOperating &hw, Context &ctx) {
    if (ctx.isTakeOffInProgress() || ctx.isLandingInProgress()) {
        task.changeState(new Measuring);
    }
}

} // namespace Operating
