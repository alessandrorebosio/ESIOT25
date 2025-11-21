#pragma once

#include <Arduino.h>

class MsgSerivce final {
  private:
    unsigned short baud;

  public:
    MsgSerivce(unsigned short baud);

    void begin();

    bool isMsgAvailable();

    String getMsg();

    void sendMsg(String text);
};
