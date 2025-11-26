#include "tasks/state/blinking/OffState.h"
#include "tasks/state/blinking/OnState.h"
#include "tasks/BlinkingTask.h"

OffState::OffState() {
}

void OffState::onEnter(BlinkingTask *bln, HWPlatform *hw, Context *ctx) {
    // led off
}

void OffState::onExit(BlinkingTask *bln, HWPlatform *hw, Context *ctx) {
}

void OffState::tick(BlinkingTask *bln, HWPlatform *hw, Context *ctx) {
    bln->changeState(new ::OnState);
}