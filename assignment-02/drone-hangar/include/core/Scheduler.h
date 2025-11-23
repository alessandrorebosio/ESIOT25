#pragma once

#include "tasks/Task.h"

#define MAX_TASKS 50

class Scheduler final {
  private:
    Task *taskList[MAX_TASKS];

    int basePeriod;
    int nTasks;

  public:
    void init(int basePeriod);

    virtual bool addTask(Task *task);

    virtual void schedule();
};
