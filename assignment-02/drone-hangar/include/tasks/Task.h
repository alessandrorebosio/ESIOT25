#pragma once

#include <Arduino.h>

class Task {
  protected:
    int period;
    int timeElapsed;

  public:
    virtual void init(int period) {
        this->period = period;
        this->timeElapsed = 0;
    }

    virtual void tick() = 0;

    bool shouldRun(int basePeriod) {
        this->timeElapsed += basePeriod;
        if (this->timeElapsed >= this->period) {
            this->timeElapsed = 0;
            return true;
        }
        return false;
    }

    void setPeriod(const int period) {
        this->period = period;
    }
};
