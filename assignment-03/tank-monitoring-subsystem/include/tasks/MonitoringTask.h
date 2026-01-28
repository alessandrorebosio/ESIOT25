#pragma once

#include "Task.h"

class MonitoringTask : public Task {
  public:
    static void exec(void *parameter);
};
