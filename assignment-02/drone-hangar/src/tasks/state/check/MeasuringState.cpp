#include "tasks/state/check/MeasuringState.h"
#include "tasks/state/check/IdleState.h"

#include "tasks/CheckTask.h"

static unsigned long timerInside = 0;
static unsigned long timerOutside = 0;

MeasuringState::MeasuringState() {
}

void MeasuringState::onEnter(CheckTask *chk, HWPlatform *hw, Context *cxt) {
    hw->serial()->sendMsg("measuring");
    timerInside = millis();
    timerOutside = millis();
}

void MeasuringState::onExit(CheckTask *chk, HWPlatform *hw, Context *cxt) {
    cxt->stopMeasuring();
}

void MeasuringState::tick(CheckTask *chk, HWPlatform *hw, Context *cxt) {
    if (hw->isOverDistance1() && hw->msgIsEqual("landing")) {
        if (hw->expiredT3(timerOutside)) {
            hw->serial()->sendMsg("outside");
            chk->changeState(new ::IdleState);
        }
    } else {
        timerOutside = millis();
    }

    if (!hw->isOverDistance2()) {
        if (hw->expiredT4(timerInside)) {
            hw->serial()->sendMsg("inside");
            chk->changeState(new ::IdleState);
            return;
        }
    } else {
        timerInside = millis();
    }
}
