#include "tasks/states/blink/Off.h"
#include "tasks/states/blink/On.h"

#include "tasks/BlinkTask.h"

Off::Off() {
}

void Off::onEnter(BlinkTask &task, Led &led, bool &enabled) {
	led.off();
}

void Off::onExit(BlinkTask &task, Led &led, bool &enabled) {
}

void Off::tick(BlinkTask &task, Led &led, bool &enabled) {
	if (enabled) {
		task.changeState(new ::On);
	}
}
