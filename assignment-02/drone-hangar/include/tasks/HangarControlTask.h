#pragma once

#include "core/MsgService.h"
#include "model/HWPlatform.h"

#include "Task.h"

class HangarControlTask : public Task {
  private:
    HWPlatform *hw;
    MsgSerivce *msg;
    enum { NORMAL, MANAGE, PREALARM, ALARM } state;

  public:
    explicit HangarControlTask(HWPlatform *hw, MsgSerivce *msg);

    explicit HangarControlTask(HWPlatform *hw, MsgSerivce *msg, int period);

    void init(int period);

    void tick();
};