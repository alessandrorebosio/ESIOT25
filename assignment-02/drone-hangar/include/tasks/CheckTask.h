#pragma once

#include "core/Context.h"
#include "model/HWPlatform.h"
#include "tasks/state/check/CheckState.h"

#include "Task.h"

class CheckTask final : public Task {
private:
  HWPlatform *hw;
  Context *context;
  CheckState *state;

public:

  explicit CheckTask(HWPlatform *hw, Context *context);

  explicit CheckTask(HWPlatform *hw, Context *context, int period);

  void init(int period);

  void tick();

  void changeState(CheckState *state) {
      if (this->state) {
          this->state->onExit(this, hw, context);
          delete this->state;
      }
      this->state = state;
      if (this->state) {
          this->state->onEnter(this, hw, context);
      }
  }

  virtual ~CheckTask() = default;

};