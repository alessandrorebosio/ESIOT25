#pragma once

#include "tasks/states/blink/BlinkState.h"

class On : public BlinkState {
  public:
	On();

	void onEnter(BlinkTask &task, Led &led, bool &enabled);

	void onExit(BlinkTask &task, Led &led, bool &enabled);

	void tick(BlinkTask &task, Led &led, bool &enabled);

	~On() = default;
};
