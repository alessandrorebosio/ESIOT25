#include "tasks/states/blink/On.h"
#include "tasks/states/blink/Off.h"

#include "tasks/BlinkTask.h"

On::On() {
}

void On::onEnter(BlinkTask &task, Led &led, bool &enabled) {
	led.on();
}

void On::onExit(BlinkTask &task, Led &led, bool &enabled) {
}

void On::tick(BlinkTask &task, Led &led, bool &enabled) {
	task.changeState(new ::Off);
}