#include "tasks/FlightTask.h"

#include "tasks/states/flight/Idle.h"
#include "tasks/states/flight/Operating.h"
#include "tasks/states/flight/Waiting.h"

#include "parameters.h"

namespace Flight {

void Idle::onEnter(FlightTask &task, HWFlight &hw, Context &ctx, MsgService &msg, const bool &enabled) {
    ctx.stopBlink();
    ctx.closeGate();
}

void Idle::onExit(FlightTask &task, HWFlight &hw, Context &ctx, MsgService &msg, const bool &enabled) {
}

void Idle::tick(FlightTask &task, HWFlight &hw, Context &ctx, MsgService &msg, const bool &enabled) {
    if (enabled && msg.isMsgAvailable()) {
        const String received = msg.receive();
        if (received.equals(TAKEOFF_MSG)) {
            if (hw.distance() < D1) {
                task.changeState(new Operating);
                // TODO: ctx.doTakeOff();
            }
        } else {
            // TODO: ctx.startMeasuring();
        }

        if (received.equals(LANDING_MSG)) {
            task.changeState(new Waiting);
        }
    }
}

} // namespace Flight
