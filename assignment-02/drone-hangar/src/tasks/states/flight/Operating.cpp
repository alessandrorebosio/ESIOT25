#include "tasks/FlightTask.h"

#include "tasks/states/flight/Idle.h"
#include "tasks/states/flight/Operating.h"

#include "parameters.h"

void Operating::onEnter(FlightTask &task, HWFlight &hw, Context &cxt, MsgService &msg, const bool &enabled) {
    msg.send(cxt.isTakeOff() ? TAKEOFF_MSG : cxt.isLanding() ? LANDING_MSG : "");
    cxt.startBlink();
    // TODO: cxt.open()
}

void Operating::onExit(FlightTask &task, HWFlight &hw, Context &cxt, MsgService &msg, const bool &enabled) {
}

void Operating::tick(FlightTask &task, HWFlight &hw, Context &cxt, MsgService &msg, const bool &enabled) {
    if (cxt.isOperationDone()) {
        task.changeState(new ::Idle);
    }
}
