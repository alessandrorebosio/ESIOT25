#pragma once

#include "tasks/states/blink/BlinkState.h"

class Off : public BlinkState {
  public:
	Off();

	void onEnter(BlinkTask &task, Led &led, bool &enabled);

	void onExit(BlinkTask &task, Led &led, bool &enabled);

	void tick(BlinkTask &task, Led &led, bool &enabled);

	~Off() = default;
};
