#include "tasks/CommunicationTask.h"

CommunicationTask::CommunicationTask(Hardware &hw, Context &ctx, int baud, int period) : hardware(hw), context(ctx) {
    Task::init(period);
    if (!Serial) {
        Serial.begin(baud);
    }
}

void CommunicationTask::tick(void) {
}
