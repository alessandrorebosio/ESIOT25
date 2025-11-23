#pragma once

#include "tasks/Task.h"
#include "devices/ProximitySensor.h"
#include "core/MsgService.h"
#include "model/Context.h"
#include <Arduino.h>

class DistanceMeasuringTask : public Task {
  public:
    explicit DistanceMeasuringTask(ProximitySensor *sonar, MsgSerivce *msg,
                                    Context *context);
    explicit DistanceMeasuringTask(ProximitySensor *sonar, MsgSerivce *msg,
                                    Context *context, int period);

    void init(int period);
    void tick();

  private:
    enum State { IDLE, MEASURING } state;
    ProximitySensor *sonar;
    MsgSerivce *msg;
    Context *context;

    void setState(State s);
};
