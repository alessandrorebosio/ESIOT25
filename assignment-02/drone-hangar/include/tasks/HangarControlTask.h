#pragma once

#include "core/MsgService.h"
#include "model/Context.h"
#include "model/HWPlatform.h"

#include "Task.h"

class HangarControlTask final : public Task {
  private:
    MsgSerivce *msg;
    Context *context;

  public:
    explicit HangarControlTask(MsgSerivce *msg, Context *context);

    explicit HangarControlTask(MsgSerivce *msg, Context *context, int period);

    void init(int period);

    void tick();
};