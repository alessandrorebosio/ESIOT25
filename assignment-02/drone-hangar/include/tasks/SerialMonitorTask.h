#pragma once

#include "Task.h"

class SerialMonitorTask : public Task {
  private:
    int baud;

  public:
    SerialMonitorTask(const int baud) : baud(baud) {}

    SerialMonitorTask(const int baud, const int period) : baud(baud) {
        this->init(period);
    }

    void init(int period);

    void tick();

    bool isMsgAvailable();

    String getMsg();
};
