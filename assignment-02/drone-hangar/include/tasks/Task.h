#pragma once

#include <Arduino.h>

class Task {
  protected:
    int period;
    int timeElapsed;
    bool active;

  public:
    virtual void init(int period) {
        this->period = period;
        this->active = true;
        timeElapsed = 0;
    }

    virtual void tick() = 0;

    bool updateAndCheckTime(int basePeriod) {
        timeElapsed += basePeriod;
        if (timeElapsed >= this->period) {
            timeElapsed = 0;
            return true;
        }
        return false;
    }

    void setPeriod(const int period) {
        this->period = period;
    }

    bool isActive() {
        return this->active;
    }

    void setActive(const bool active) {
        this->active = active;
    }
};
