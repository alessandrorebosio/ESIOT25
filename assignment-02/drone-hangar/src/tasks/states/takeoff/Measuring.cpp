#include "tasks/TakeOffTask.h"

#include "tasks/states/takeoff/Idle.h"
#include "tasks/states/takeoff/Measuring.h"

#include "parameters.h"

namespace TakeOff {

void Measuring::onEnter(TakeOffTask &task, HWTakeOff &hw, Context &ctx, const bool &enabled) {
    this->timer = millis();
    Serial.println("Measuring");
}

void Measuring::onExit(TakeOffTask &task, HWTakeOff &hw, Context &ctx, const bool &enabled) {
}

void Measuring::tick(TakeOffTask &task, HWTakeOff &hw, Context &ctx, const bool &enabled) {
    if (hw.distance() > D1) {
        if (millis() - this->timer >= T3) {
            task.changeState(new Idle);
            ctx.printOutside();
            ctx.takeOffDone();
        }
    } else {
        this->timer = millis();
    }
}

} // namespace TakeOff
