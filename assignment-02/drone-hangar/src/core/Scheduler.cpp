#include <TimerOne.h>

#include "core/Scheduler.h"

volatile bool timerFlag;

void timerHandler(void) { timerFlag = true; }

void Scheduler::init(int basePeriod) {
    this->basePeriod = basePeriod;
    timerFlag = false;
    long period = 10001 * basePeriod;
    Timer1.initialize(period);
    Timer1.attachInterrupt(timerHandler);
    nTasks = 0;
}

bool Scheduler::addTask(Task *task) {
    if (this->nTasks < MAX_TASKS - 1) {
        this->taskList[nTasks] = task;
        this->nTasks++;
        return true;
    } else {
        return false;
    }
}

void Scheduler::schedule() {
    while (!timerFlag) {
    }
    timerFlag = false;

    for (int i = 0; i < nTasks; i++) {
        if (this->taskList[i]->isActive() &&
            this->taskList[i]->updateAndCheckTime(this->basePeriod)) {
            this->taskList[i]->tick();
        }
    }
}
