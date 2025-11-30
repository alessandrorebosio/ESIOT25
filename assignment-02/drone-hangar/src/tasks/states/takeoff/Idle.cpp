#include "tasks/TakeOffTask.h"

#include "tasks/states/takeoff/Idle.h"
#include "tasks/states/takeoff/Measuring.h"

namespace TakeOff {

void Idle::onEnter(TakeOffTask &task, HWTakeOff &hw, Context &ctx, const bool &enabled) {
    Serial.println("idle");
}

void Idle::onExit(TakeOffTask &task, HWTakeOff &hw, Context &ctx, const bool &enabled) {
}

void Idle::tick(TakeOffTask &task, HWTakeOff &hw, Context &ctx, const bool &enabled) {
    if (enabled) {
        task.changeState(new Measuring);
    }
}

} // namespace TakeOff
