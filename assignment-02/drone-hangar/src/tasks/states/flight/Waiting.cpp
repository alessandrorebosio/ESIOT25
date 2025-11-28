#include "tasks/FlightTask.h"

#include "tasks/states/flight/Idle.h"
#include "tasks/states/flight/Operating.h"
#include "tasks/states/flight/Waiting.h"

#include "parameters.h"

static unsigned long timer = 0;

void Waiting::onEnter(FlightTask &task, HWFlight &hw, Context &cxt, MsgService &msg, const bool &enabled) {
    timer = millis();
}

void Waiting::onExit(FlightTask &task, HWFlight &hw, Context &cxt, MsgService &msg, const bool &enabled) {
}

void Waiting::tick(FlightTask &task, HWFlight &hw, Context &cxt, MsgService &msg, const bool &enabled) {
    if (millis() - timer <= T3) {
        if (hw.isDetected()) {
            task.changeState(new ::Operating);
            cxt.doLanding();
        }
    } else {
        task.changeState(new ::Idle);
    }
}
