#include "tasks/state/check/MeasuringState.h"
#include "tasks/state/check/IdleState.h"

#include "tasks/CheckTask.h"

static unsigned long timer = 0;

MeasuringState::MeasuringState(){
}

void MeasuringState::onEnter(CheckTask *chk, HWPlatform *hw, Context *cxt) {
    hw->serial()->sendMsg("measuring");
    timer = millis();
}

void MeasuringState::onExit(CheckTask *chk, HWPlatform *hw, Context *cxt) {
    // cxt->stopMeasuring();
}

void MeasuringState::tick(CheckTask *chk, HWPlatform *hw, Context *cxt) {
    if(hw->isOverDistance1()){
        if(hw->expiredT3(timer)){
            timer = millis();
            hw->serial()->sendMsg("outside");
            chk->changeState(new ::IdleState);
        }
    } else {
        timer = millis();
    }

    if(!hw->isOverDistance2()){
        if(hw->expiredT4(timer)){
            timer = millis();
            hw->serial()->sendMsg("outside");
            chk->changeState(new ::IdleState);
        }
    } else {
        timer = millis();
    }
}