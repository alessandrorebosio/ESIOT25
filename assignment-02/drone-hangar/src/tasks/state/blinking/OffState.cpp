#include "tasks/state/blinking/OffState.h"
#include "tasks/state/blinking/OnState.h"

#include "tasks/BlinkingTask.h"

OffState::OffState() {
}

void OffState::onEnter(BlinkingTask *bln, HWPlatform *hw, Context *ctx) {
    hw->turnOffL2();
}

void OffState::onExit(BlinkingTask *bln, HWPlatform *hw, Context *ctx) {
}

void OffState::tick(BlinkingTask *bln, HWPlatform *hw, Context *ctx) {
    if(ctx->shouldBlink()) {
        bln->changeState(new ::OnState);
    }
}