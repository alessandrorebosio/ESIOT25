#pragma once

#include "Task.h"
#include "devices/Light.h"

class BlinkingTask : public Task {
  private:
    Light *led;
    bool isOn;

  public:
    explicit BlinkingTask(Light *led);

    explicit BlinkingTask(Light *led, int period);

    void init(int period);

    void tick();
};
