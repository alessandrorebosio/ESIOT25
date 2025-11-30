#include "tasks/LandingTask.h"

#include "tasks/states/landing/Idle.h"
#include "tasks/states/landing/Measuring.h"

#include "parameters.h"

namespace Landing {

void Measuring::onEnter(LandingTask &task, HWLanding &hw, Context &ctx, const bool &enabled) {
    this->timer = millis();
}

void Measuring::onExit(LandingTask &task, HWLanding &hw, Context &ctx, const bool &enabled) {
}

void Measuring::tick(LandingTask &task, HWLanding &hw, Context &ctx, const bool &enabled) {
    if (hw.distance() < D2) {
        if (millis() - this->timer >= T4) {
            task.changeState(new Idle);
            ctx.printInside();
            ctx.landingDone();
        }
    } else {
        this->timer = millis();
    }
}

} // namespace Landing
