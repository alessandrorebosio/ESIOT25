#include "tasks/states/blink/Off.h"
#include "tasks/states/blink/On.h"

#include "tasks/BlinkTask.h"

namespace Blink {

void Off::onEnter(BlinkTask &task, HWBlink &hw, const bool &enabled) {
    hw.turnOff();
}

void Off::onExit(BlinkTask &task, HWBlink &hw, const bool &enabled) {
}

void Off::tick(BlinkTask &task, HWBlink &hw, const bool &enabled) {
    if (enabled) {
        task.changeState(new On);
    }
}

} // namespace Blink
