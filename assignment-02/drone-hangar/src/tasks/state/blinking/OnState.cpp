#include "tasks/state/blinking/OnState.h"
#include "tasks/state/blinking/OffState.h"
#include "tasks/BlinkingTask.h"

OnState::OnState() {
}

void OnState::onEnter(BlinkingTask *bln, HWPlatform *hw, Context *ctx) {
    hw->turnOnL2();
}

void OnState::onExit(BlinkingTask *bln, HWPlatform *hw, Context *ctx) {
}

void OnState::tick(BlinkingTask *bln, HWPlatform *hw, Context *ctx) {
    bln->changeState(new ::OffState);
}