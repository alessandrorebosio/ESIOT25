#pragma once

#include "core/MsgService.h"
#include "model/Context.h"
#include "model/HWPlatform.h"

#include "Task.h"

class HangarControlTask final : public Task {
  private:
    HWPlatform *hw;
    MsgService *serial;
    Context *context;
    enum State { NORMAL, OPERATING, WAITING, PREALARM, ALARM } state;
    int freeRAM();

  public:
    explicit HangarControlTask(HWPlatform *hw, MsgService *msg,
                               Context *context);

    explicit HangarControlTask(HWPlatform *hw, MsgService *msg,
                               Context *context, int period);

    void init(int period);

    void tick();
};