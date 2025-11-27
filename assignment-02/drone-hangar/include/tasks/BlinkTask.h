#pragma once

#include <Led.h>

#include "core/Context.h"
#include "tasks/states/blink/BlinkState.h"

#include "Task.h"

class BlinkTask final : public Task {
  private:
	Led &led;
	bool &enabled;
	BlinkState *state;

  public:
	explicit BlinkTask(Led &led, bool &enabled, int period);

	void tick() override;

	void changeState(BlinkState *newState);

	~BlinkTask() = default;
};
