#pragma once

#include "core/MsgService.h"
#include "devices/ProximitySensor.h"
#include "model/Context.h"

#include "Task.h"

class DistanceMeasuringTask : public Task {
  private:
    ProximitySensor *sonar;
    MsgService *msg;
    Context *context;

    enum State { IDLE, MEASURING } state;

  public:
    explicit DistanceMeasuringTask(ProximitySensor *sonar, MsgService *msg,
                                   Context *context);
    explicit DistanceMeasuringTask(ProximitySensor *sonar, MsgService *msg,
                                   Context *context, int period);

    void init(int period);
    void tick();
};
