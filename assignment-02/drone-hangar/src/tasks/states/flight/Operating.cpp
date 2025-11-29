#include "tasks/FlightTask.h"

#include "tasks/states/flight/Idle.h"
#include "tasks/states/flight/Operating.h"

#include "parameters.h"

namespace Flight {

void Operating::onEnter(FlightTask &task, HWFlight &hw, Context &ctx, MsgService &msg, const bool &enabled) {
    // msg.send(ctx.isTakeOff() ? TAKEOFF_MSG : ctx.isLanding() ? LANDING_MSG : "");
    // hw.printOnLcd(ctx.isTakeOff() ? TAKEOFF_MSG : ctx.isLanding() ? LANDING_MSG : "");
    ctx.startBlink();
    ctx.openGate();
}

void Operating::onExit(FlightTask &task, HWFlight &hw, Context &ctx, MsgService &msg, const bool &enabled) {
}

void Operating::tick(FlightTask &task, HWFlight &hw, Context &ctx, MsgService &msg, const bool &enabled) {
    // if (ctx.isOperationDone()) {
    //     task.changeState(new Idle);
    // }
}

} // namespace Flight
