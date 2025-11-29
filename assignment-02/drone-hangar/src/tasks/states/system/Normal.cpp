#include "tasks/states/system/Normal.h"
#include "tasks/SystemTask.h"
#include "tasks/states/system/PreAlarm.h"

#include "parameters.h"

static unsigned long timer;

namespace System {

void Normal::onEnter(SystemTask &task, HWSystem &hw, Context &ctx) {
	ctx.printNormal();
	hw.turnOnLed();
	ctx.allowFlight();
	timer = millis();
}

void Normal::onExit(SystemTask &task, HWSystem &hw, Context &ctx) {
	ctx.blockFlight();
}

void Normal::tick(SystemTask &task, HWSystem &hw, Context &ctx) {
	if (hw.temperature() > TEMP1) {
		if (millis() - timer >= T1) {
			task.changeState(new PreAlarm);
		}
	} else {
		timer = millis();
	}
}

} // namespace System
