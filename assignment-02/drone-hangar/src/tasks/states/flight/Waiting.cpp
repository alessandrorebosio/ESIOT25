#include "tasks/FlightTask.h"

#include "tasks/states/flight/Idle.h"
#include "tasks/states/flight/Operating.h"
#include "tasks/states/flight/Waiting.h"

#include "parameters.h"

static unsigned long timer = 0;

namespace Flight {

void Waiting::onEnter(FlightTask &task, HWFlight &hw, Context &ctx, const bool &enabled) {
    timer = millis();
}

void Waiting::onExit(FlightTask &task, HWFlight &hw, Context &ctx, const bool &enabled) {
}

void Waiting::tick(FlightTask &task, HWFlight &hw, Context &ctx, const bool &enabled) {
    if (millis() - timer <= T5) {
        if (hw.isDetected()) {
            task.changeState(new Operating);
            // TODO: ctx.doLanding();
        }
    } else {
        task.changeState(new Idle);
    }
}

} // namespace Flight
