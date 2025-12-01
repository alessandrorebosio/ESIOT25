#include "tasks/states/operating/Measuring.h"
#include "tasks/OperatingTask.h"
#include "tasks/states/operating/Idle.h"

#include "parameters.h"

namespace Operating {

void Measuring::onEnter(OperatingTask &task, HWOperating &hw, Context &ctx) {
    Serial.println("Measuring");
    this->takeOffTimer = millis();
    this->landingTimer = millis();
}

void Measuring::onExit(OperatingTask &task, HWOperating &hw, Context &ctx) {
}

void Measuring::tick(OperatingTask &task, HWOperating &hw, Context &ctx) {
    if (ctx.isTakeOffInProgress()) {
        if (hw.distance() >= D1) {
            if (millis() - this->takeOffTimer >= T3) {
                task.changeState(new Idle);
                ctx.printOutside();
                ctx.takeOffDone();
            }
        } else {
            this->takeOffTimer = millis();
        }
    }

    if (ctx.isLandingInProgress()) {
        if (hw.distance() <= D1) {
            if (millis() - this->landingTimer >= T4) {
                task.changeState(new Idle);
                ctx.printInside();
                ctx.landingDone();
            }
        } else {
            this->landingTimer = millis();
        }
    }
}

} // namespace Operating
