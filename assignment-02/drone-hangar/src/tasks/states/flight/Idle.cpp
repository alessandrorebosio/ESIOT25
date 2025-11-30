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
        if (ctx.isTakeOffMsg()) {
            if (hw.distance() < D1) {
                task.changeState(new Operating);
                ctx.printTakeOff();
                ctx.doTakeOff();
            }
        }

        if (ctx.isLandingMsg()) {
            task.changeState(new Waiting);
        }
    }
}

} // namespace Flight
