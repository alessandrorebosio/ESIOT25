#include "core/Scheduler.h"

#include <TimerOne.h>

volatile bool timerFlag;

void timerHandler(void) {
    timerFlag = true;
}

Scheduler::Scheduler()
    : context(nullptr), basePeriod(0), nTasks(0), lastExecutionTime(0) {
}

Scheduler::Scheduler(Context *context)
    : context(context), basePeriod(0), nTasks(0), lastExecutionTime(0) {
}

void Scheduler::init(int basePeriod) {
    this->basePeriod = basePeriod;
    timerFlag = false;
    Timer1.initialize((unsigned long)basePeriod * 1000UL);
    Timer1.attachInterrupt(timerHandler);
    nTasks = 0;
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

    for (int i = 0; i < nTasks; i++) {
        if (this->taskList[i]->shouldRun(this->basePeriod)) {
            this->taskList[i]->tick();
        }
    }
}

Context *Scheduler::getContext() {
    return this->context;
}
