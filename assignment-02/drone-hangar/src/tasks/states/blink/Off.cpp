#include "tasks/states/blink/Off.h"
#include "tasks/states/blink/On.h"

#include "tasks/BlinkTask.h"

namespace Blink {

void Off::onEnter(BlinkTask &task, Led &led, const bool &enabled) {
    led.off();
}

void Off::onExit(BlinkTask &task, Led &led, const bool &enabled) {
}

void Off::tick(BlinkTask &task, Led &led, const bool &enabled) {
    if (enabled) {
        task.changeState(new On);
    }
}

} // namespace Blink
