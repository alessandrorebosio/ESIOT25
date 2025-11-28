#include "tasks/FlightTask.h"

#include "tasks/states/flight/Idle.h"
#include "tasks/states/flight/Operating.h"

#include "parameters.h"

void Operating::onEnter(FlightTask &task, HWFlight &hw, Context &ctx, MsgService &msg, const bool &enabled) {
    msg.send(ctx.isTakeOff() ? TAKEOFF_MSG : ctx.isLanding() ? LANDING_MSG : "");
    ctx.startBlink();
    // TODO: ctx.open()
}

void Operating::onExit(FlightTask &task, HWFlight &hw, Context &ctx, MsgService &msg, const bool &enabled) {
}

void Operating::tick(FlightTask &task, HWFlight &hw, Context &ctx, MsgService &msg, const bool &enabled) {
    if (ctx.isOperationDone()) {
        task.changeState(new ::Idle);
    }
}
