#include "core/Scheduler.h"

#include <TimerOne.h>

volatile bool timerFlag = false;

/**
 * @brief Timer interrupt handler function.
 * 
 * This function is called by Timer1 interrupt and sets the timerFlag to true.
 */
void timerHandler() {
    timerFlag = true;
}

/**
 * @brief Initializes the scheduler with a specified period.
 * 
 * Sets up Timer1 with the given period and attaches the interrupt handler.
 * 
 * @param periodMs The scheduling period in milliseconds
 */
void Scheduler::init(unsigned long periodMs) {
    timerFlag = false;
    this->nTasks = 0;
    Timer1.initialize(periodMs * 1000UL);
    Timer1.attachInterrupt(timerHandler);
}

/**
 * @brief Adds a task to the scheduler.
 * 
 * @param task Pointer to the task to be added
 * @return true if the task was successfully added, false if the scheduler is full
 */
bool Scheduler::addTask(Task *task) {
    if (this->nTasks < MAX_TASKS) {
        this->taskList[nTasks] = task;
        this->nTasks++;
        return true;
    }
    return false;
}

/**
 * @brief Executes the scheduling loop.
 * 
 * Waits for the timer interrupt flag, then checks and executes all tasks
 * that are due to run based on their timing requirements.
 */
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

/**
 * @brief Destructor that cleans up all scheduled tasks.
 * 
 * Deletes all task objects that were added to the scheduler to prevent memory leaks.
 */
Scheduler::~Scheduler() {
    for (int i = 0; i < this->nTasks; ++i) {
        delete this->taskList[i];
        this->taskList[i] = nullptr;
    }
    this->nTasks = 0;
}
