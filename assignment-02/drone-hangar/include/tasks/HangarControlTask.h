#pragma once

#include "SerialMonitorTask.h"
#include "Task.h"
#include "model/HWPlatform.h"

class HangarControlTask : public Task {
  private:
    HWPlatform *hw;
    SerialMonitorTask *serialMonitor;

    enum { WAITING } state;

  public:
    HangarControlTask(HWPlatform *hw, SerialMonitorTask *serialMonitor)
        : hw(hw), serialMonitor(serialMonitor) {
    }

    HangarControlTask(HWPlatform *hw, SerialMonitorTask *serialMonitor,
                      const int period)
        : HangarControlTask(hw, serialMonitor) {
        this->init(period);
    }

    void init(int period);

    void tick();
};
