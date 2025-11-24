#include "core/MsgService.h"

MsgService::MsgService(const unsigned short baud) : baud(baud) {
    this->begin();
}

void MsgService::begin() {
    Serial.begin(this->baud);
}

void MsgService::sendMsg(const String text) {
    Serial.println(text);
}

bool MsgService::isMsgAvailable() {
    return Serial.available() > 0;
}

void MsgService::read() {
    while (this->isMsgAvailable()) {
        this->msg += (char)Serial.read();
    }
}

void MsgService::clear() {
    this->msg = "";
}

String MsgService::getMsg() {
    return this->msg;
}
