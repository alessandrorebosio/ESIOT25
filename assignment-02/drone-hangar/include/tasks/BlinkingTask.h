#pragma once

#include "devices/Light.h"
#include "model/Context.h"

#include "Task.h"

class BlinkingTask final : public Task {
  private:
    Light *led;
    Context *context;
    bool isOn;

  public:
    explicit BlinkingTask(Light *led, Context *context);

    explicit BlinkingTask(Light *led, Context *context, int period);

    void init(int period);

    void init();

    void tick();
};
