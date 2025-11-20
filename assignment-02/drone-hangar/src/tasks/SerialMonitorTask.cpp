#include "tasks/SerialMonitorTask.h"

void SerialMonitorTask::init(const int period) {
    Task::init(period);
    Serial.begin(this->baud);
}

void SerialMonitorTask::tick() { Serial.print("TODO"); }

bool SerialMonitorTask::isMsgAvailable() { return Serial.available() > 0; }

String SerialMonitorTask::getMsg() {
    String msg = "";
    while (this->isMsgAvailable()) {
        msg += Serial.read();
    }
    return msg;
}
