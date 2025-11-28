#include "tasks/states/blink/On.h"
#include "tasks/states/blink/Off.h"

#include "tasks/BlinkTask.h"

namespace Blink {

void On::onEnter(BlinkTask &task, HWBlink &hw, const bool &enabled) {
    hw.turnOn();
}

void On::onExit(BlinkTask &task, HWBlink &hw, const bool &enabled) {
}

void On::tick(BlinkTask &task, HWBlink &hw, const bool &enabled) {
    task.changeState(new Off);
}

} // namespace Blink
