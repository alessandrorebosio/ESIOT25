#include "tasks/CheckTask.h"

#include "tasks/states/check/Idle.h"
#include "tasks/states/check/Measuring.h"

#include "parameters.h"

static unsigned long takeOffTimer = 0;
static unsigned long landingTimer = 0;

namespace Check {

void Measuring::onEnter(CheckTask &task, HWCheck &hw, Context &ctx, MsgService &msg, const bool &enabled) {
    takeOffTimer = millis();
    landingTimer = millis();
}

void Measuring::onExit(CheckTask &task, HWCheck &hw, Context &ctx, MsgService &msg, const bool &enabled) {
    // ctx.stopMeasuring();
}

void Measuring::tick(CheckTask &task, HWCheck &hw, Context &ctx, MsgService &msg, const bool &enabled) {
    // if (ctx.shouldMeasure() || ctx.isTakeOff()) {
    //     if (hw.distance() > D1) {
    //         if (millis() - takeOffTimer >= T3) {
    //             task.changeState(new Idle);
    //             hw.printOnLcd(OUTSIDE_MSG);
    //             msg.send(OUTSIDE_MSG);
    //             if (ctx.isTakeOff()) {
    //                 ctx.takeOffDone();
    //             }
    //         }
    //     } else {
    //         takeOffTimer = millis();
    //     }
    // }

    // if (ctx.shouldMeasure() || ctx.isLanding()) {
    //     if (hw.distance() < D2) {
    //         if (millis() - landingTimer >= T4) {
    //             task.changeState(new Idle);
    //             hw.printOnLcd(INSIDE_MSG);
    //             msg.send(INSIDE_MSG);
    //             if (ctx.isLanding()) {
    //                 ctx.landingDone();
    //             }
    //         }
    //     } else {
    //         landingTimer = millis();
    //     }
    // }
}

} // namespace Check
