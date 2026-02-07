#include "tasks/CommunicationTask.h"

/**
 * @brief Initialize communication task
 */
CommunicationTask::CommunicationTask(Hardware &hw, Context &ctx, int baud, int period) : hardware(hw), context(ctx) {
    Task::init(period);
    Serial.begin(baud);
}

/**
 * @brief Periodically check for serial input and process commands
 */
void CommunicationTask::tick(void) {
    if (Serial.available() > 0) {
        String input = Serial.readString();
        this->context.updateLastMsgTime();

        if (isDigit(input[0])) {
            int val = input.toInt();
            if (val >= 0 && val <= 90) {
                this->context.setPosition(val);
            }
        }
    }
}
