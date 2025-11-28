#include "tasks/states/blink/On.h"
#include "tasks/states/blink/Off.h"

#include "tasks/BlinkTask.h"

namespace Blink {

void On::onEnter(BlinkTask &task, Led &led, const bool &enabled) {
    led.on();
}

void On::onExit(BlinkTask &task, Led &led, const bool &enabled) {
}

void On::tick(BlinkTask &task, Led &led, const bool &enabled) {
    task.changeState(new Off);
}

} // namespace Blink
