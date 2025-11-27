#include "core/Scheduler.h"

#include <TimerOne.h>

volatile bool timerFlag = false;

void timerHandler() {
	timerFlag = true;
}

void Scheduler::init(unsigned long periodMs) {
	timerFlag = false;
	Timer1.initialize(periodMs * 1000UL);
	Timer1.attachInterrupt(timerHandler);
}

bool Scheduler::addTask(Task *task) {
	if (this->nTasks < MAX_TASKS) {
		this->taskList[nTasks] = task;
		this->nTasks++;
		return true;
	}
	return false;
}

void Scheduler::schedule() {
	while (!timerFlag) {
	}
	timerFlag = false;

	unsigned long currentTime = micros();

	for (int i = 0; i < nTasks; i++) {
		if (this->taskList[i]->shouldRun(currentTime)) {
			this->taskList[i]->tick();
		}
	}
}
