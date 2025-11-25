#include "core/MsgService.h"

MsgSerivce::MsgSerivce(const unsigned short baud) : baud(baud) {
    this->begin();
}

void MsgSerivce::begin() {
    Serial.begin(this->baud);
}

void MsgSerivce::sendMsg(const String text) {
    Serial.println(text);
}

bool MsgSerivce::isMsgAvailable() {
    return Serial.available() > 0;
}

String MsgSerivce::getMsg() {
    String msg = "";
    while (this->isMsgAvailable()) {
        msg += (char)Serial.read();
    }
    return msg;
}
