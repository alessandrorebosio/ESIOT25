#pragma once

class BlinkTask;
class Led;

class BlinkState {
  public:
	virtual void onEnter(BlinkTask &task, Led &led, bool &enabled) = 0;

	virtual void onExit(BlinkTask &task, Led &led, bool &enabled) = 0;

	virtual void tick(BlinkTask &task, Led &led, bool &enabled) = 0;

	virtual ~BlinkState() = default;
};
