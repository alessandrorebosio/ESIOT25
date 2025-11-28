#pragma once

#include <Arduino.h>

class MsgService final {
  public:
    void init(unsigned int baud);

    bool isMsgAvailable();

    String receive();

    void send(String text);

    ~MsgService() = default;
};
