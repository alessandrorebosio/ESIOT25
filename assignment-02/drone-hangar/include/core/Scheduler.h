#pragma once

#include "tasks/Task.h"

#define MAX_TASKS 50

class Scheduler final {
  private:
	Task *taskList[MAX_TASKS];
	int nTasks;

  public:
	Scheduler(unsigned long periodMs);

	void init(unsigned long periodMs);

	bool addTask(Task *task);

	void schedule(void);

	~Scheduler() = default;
};
