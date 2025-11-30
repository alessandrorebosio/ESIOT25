#include "tasks/LandingTask.h"

#include "tasks/states/landing/Measuring.h"
#include "tasks/states/landing/Idle.h"

namespace Landing {

void Idle::onEnter(LandingTask &task, HWLanding &hw, Context &ctx, const bool &enabled) {
    Serial.println("idle");
}

void Idle::onExit(LandingTask &task, HWLanding &hw, Context &ctx, const bool &enabled) {

}

void Idle::tick(LandingTask &task, HWLanding &hw, Context &ctx, const bool &enabled) {
    if (enabled) {
        task.changeState(new Measuring);
    }
}


} // namespace Landing
