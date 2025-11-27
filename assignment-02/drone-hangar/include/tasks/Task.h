#pragma once

#include <Arduino.h>

class Task {
  protected:
	unsigned long period;
	unsigned long lastRun;

  public:
	void init(unsigned long periodMs) {
		this->period = periodMs * 1000UL;
		this->lastRun = 0;
	}

	bool shouldRun(unsigned long currentTime) {
		if ((currentTime - lastRun) >= period) {
			lastRun = currentTime;
			return true;
		}
		return false;
	}

	virtual void tick() = 0;

	virtual ~Task() = default;
};
