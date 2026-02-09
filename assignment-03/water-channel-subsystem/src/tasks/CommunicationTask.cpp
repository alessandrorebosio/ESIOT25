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
        this->context.updateLastMsgTime();

        if (isDigit(input[0])) {
            this->context.setPosition(constrain(input.toInt(), 0, 100));
        } else {
            input.toUpperCase();
            if (input.equals("C")) {
                Serial.println(input);
                this->context.changeTo();
            }
        }
    }

    if (this->context.needResponse()) {
        Serial.println(this->context.popResponse());
    }
}
