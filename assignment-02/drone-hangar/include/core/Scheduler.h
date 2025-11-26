#pragma once

#include "core/Context.h"
#include "tasks/Task.h"

#define MAX_TASKS 50

class Scheduler {
  private:
    Task *taskList[MAX_TASKS];
    Context *context;

    int basePeriod;
    int nTasks;
    unsigned long lastExecutionTime;

  public:
    explicit Scheduler();

    explicit Scheduler(Context *context);

    void init(int basePeriod);

    virtual bool addTask(Task *task);

    virtual void schedule();

    Context *getContext();

    ~Scheduler() = default;
};
