#pragma once

#include <Arduino.h>

class MsgService final {
  private:
    String msg;
    unsigned short baud;

  public:
    MsgService(unsigned short baud);

    void begin();

    bool isMsgAvailable();

    void read();

    void clear();

    String getMsg();

    void sendMsg(String text);

    ~MsgService() = default;
};
