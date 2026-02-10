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
        String input = Serial.readStringUntil('\n');
        input.trim();
        if (input.length() == 0) {
            return;
        }
        this->context.recordLastMessageTime();

        if (isDigit(input[0])) {
            this->context.setValvePercentage(constrain(input.toInt(), 0, 100));
        } else {
            input.toUpperCase();
            if (input.equals("M") && this->context.isConnected()) {
                this->context.requestModeToggle();
            }
            if (input.equals("U")) {
                this->context.setDisconnected();
            }
            if (input.equals("C")) {
                this->context.setConnected();
            }
        }
    }

    if (this->context.needResponse()) {
        Serial.println(this->context.popResponse());
    }
}
