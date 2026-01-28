#pragma once

#include "Task.h"

class LedTask : public Task {
  public:
    static void exec(void *parameter);
};
