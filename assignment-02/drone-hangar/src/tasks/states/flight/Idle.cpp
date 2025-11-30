#include "tasks/FlightTask.h"

#include "tasks/states/flight/Idle.h"
#include "tasks/states/flight/Operating.h"
#include "tasks/states/flight/Waiting.h"

#include "parameters.h"

namespace Flight {

void Idle::onEnter(FlightTask &task, HWFlight &hw, Context &ctx, const bool &enabled) {
    ctx.stopBlink();
    ctx.closeGate();
}

void Idle::onExit(FlightTask &task, HWFlight &hw, Context &ctx, const bool &enabled) {
}

void Idle::tick(FlightTask &task, HWFlight &hw, Context &ctx, const bool &enabled) {
    if (enabled) {
        if (false) { // TODO: ctx.isTakeOff()
            if (hw.distance() < D1) {
                task.changeState(new Operating);
                // TODO: ctx.doTakeOff();
            }
        }

        if (false) { // TODO: ctx.isLanding()
            task.changeState(new Waiting);
        }
    }
}

} // namespace Flight
