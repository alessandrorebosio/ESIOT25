#include "tasks/CheckTask.h"

#include "tasks/states/check/Idle.h"
#include "tasks/states/check/Measuring.h"

#include "parameters.h"

static unsigned long takeOffTimer = 0;
static unsigned long landingTimer = 0;

namespace Check {

void Measuring::onEnter(CheckTask &task, HWCheck &hw, Context &ctx, const bool &enabled) {
    takeOffTimer = millis();
    landingTimer = millis();
}

void Measuring::onExit(CheckTask &task, HWCheck &hw, Context &ctx, const bool &enabled) {
    // ctx.stopMeasuring();
}

void Measuring::tick(CheckTask &task, HWCheck &hw, Context &ctx, const bool &enabled) {
    Serial.println("distance: " + String(hw.distance()));
    if (hw.distance() > D1) {
        if (millis() - takeOffTimer >= T3) {
            task.changeState(new Idle);
            ctx.printOutside();
        }
    } else {
        takeOffTimer = millis();
    }

    if (hw.distance() < D2) {
        if (millis() - landingTimer >= T4) {
            task.changeState(new Idle);
            ctx.printInside();
        }
    } else {
        landingTimer = millis();
    }
}

} // namespace Check
