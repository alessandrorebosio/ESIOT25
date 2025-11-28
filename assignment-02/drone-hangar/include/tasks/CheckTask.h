#pragma once

#include "core/Context.h"
#include "core/MsgService.h"

#include "model/check/HWCheck.h"
#include "tasks/states/check/CheckState.h"

#include "Task.h"

namespace Check {
  
class CheckTask final : public Task {
  private:
    HWCheck hardware;
    Context &context;
    MsgService &msg;
    const bool &enabled;
    CheckState *state;

  public:
    explicit CheckTask(Sonar &sonar, TMP36 &temp, Lcd &lcd, Context &ctx, MsgService &msg, const bool &enabled, int period);

    void tick();

    void changeState(CheckState *state);

    ~CheckTask();
};

} // namespace Check
