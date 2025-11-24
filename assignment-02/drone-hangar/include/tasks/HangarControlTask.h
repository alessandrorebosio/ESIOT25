#pragma once

#include "core/MsgService.h"
#include "model/Context.h"
#include "model/HWPlatform.h"

#include "Task.h"

class HangarControlTask final : public Task {
  private:
    HWPlatform *hw;
    MsgSerivce *msg;
    Context *context;
    enum State { NORMAL, OPERATING, WAITING, PREALARM, ALARM } state;

    int currentPos;
    long stateStartTime;

    void setState(State s);
    inline bool elapsedTime(unsigned long time);

    String toString(State s) {
        switch (s) {
            case NORMAL:
                return "NORMAL";
            case OPERATING:
                return "OPERATING";
            case WAITING:
                return "WAITING";
            case PREALARM:
                return "PREALARM";
            case ALARM:
                return "ALARM";
            default:
                return "UNKNOWN";
        }
    }

  public:
    explicit HangarControlTask(HWPlatform *hw, MsgSerivce *msg,
                               Context *context);

    explicit HangarControlTask(HWPlatform *hw, MsgSerivce *msg,
                               Context *context, int period);

    void init(int period);

    void tick();
};