#include "core/MsgService.h"

void MsgService::init(unsigned int baud) {
    Serial.begin(baud);
}

void MsgService::send(const String text) {
    Serial.println(text);
}

bool MsgService::isMsgAvailable() {
    return Serial.available() > 0;
}

String MsgService::receive() {
    String msg = "";
    while (this->isMsgAvailable()) {
        msg += (char)Serial.read();
    }
    return msg;
}
