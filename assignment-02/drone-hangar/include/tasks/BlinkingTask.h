#pragma once

#include "Task.h"
#include "devices/Light.h"

class BlinkingTask : public Task {
  private:
    Light *led;
    enum { ON, OFF } state;

  public:
    BlinkingTask(Light *led) : led(led) {
    }

    BlinkingTask(Light *led, int period) : BlinkingTask(led) {
        this->init(period);
    }

    void init(int period);

    void tick();
};
