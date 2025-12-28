#pragma once

#include "tasks/Task.h"

#define MAX_TASKS 10

/**
 * @brief Task scheduler class for managing periodic tasks.
 * 
 * This class provides a cooperative scheduler that manages multiple tasks
 * and executes them based on a fixed time period using Timer1 interrupts.
 */
class Scheduler final {
  private:
	Task *taskList[MAX_TASKS];
	int nTasks;

  public:
	/**
	 * @brief Initializes the scheduler with a specified period.
	 * 
	 * @param periodMs The scheduling period in milliseconds
	 */
	void init(unsigned long periodMs);

	/**
	 * @brief Adds a task to the scheduler.
	 * 
	 * @param task Pointer to the task to be added
	 * @return true if the task was successfully added, false if the scheduler is full
	 */
	bool addTask(Task *task);

	/**
	 * @brief Executes the scheduling loop.
	 * 
	 * This method should be called in the main loop. It waits for the timer interrupt
	 * and then executes all tasks that are due to run.
	 */
	void schedule(void);

	/**
	 * @brief Destructor that cleans up all scheduled tasks.
	 * 
	 * Deletes all task objects that were added to the scheduler to prevent memory leaks.
	 */
	~Scheduler();
};
