#pragma once

#include "core/Context.h"
#include "model/system/HWSystem.h"
#include "tasks/states/system/SystemState.h"

#include "Task.h"

class SystemTask final : public Task {
  private:
    HWSystem hardware;
    Context &context;
    SystemState *state;

  public:
    explicit SystemTask(Button &btn, Led &led, TMP36 &sensor, Context &cxt, int period);

    void tick() override;

    void changeState(SystemState *newState);

    ~SystemTask() = default;
};
