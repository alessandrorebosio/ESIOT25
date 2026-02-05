#pragma once

#include "Task.h"
#include "core/Context.h"
#include "model/Hardware.h"

class CommunicationTask final : public Task {
  private:
    Hardware &hardware;
    Context &context;

  public:
    explicit CommunicationTask(Hardware &hw, Context &ctx, int baud, int period);

    void tick(void) override;

    ~CommunicationTask() = default;
};
