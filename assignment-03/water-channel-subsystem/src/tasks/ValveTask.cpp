#include "tasks/ValveTask.h"

#define MIN 0
#define MAX 90

/**
 * @brief Initialize valve control task
 */
ValveTask::ValveTask(Hardware &hw, Context &ctx, int period) : hardware(hw), context(ctx) {
    Task::init(period);
    this->hardware.motorOn();
}

/**
 * @brief Periodically control valve position based on mode
 *
 * Manual mode: potentiometer sets position
 * Automatic mode: context target sets position
 * Converts percentage (0-100%) to motor degrees (0-90°)
 * Updates motor position only if different from current position
 */
void ValveTask::tick(void) {
    uint8_t perc = this->context.isAutomatic() ? this->context.getPosition() : map(this->hardware.getPotValue(), 0, 1023, 0, 100);
    uint8_t targetPos = map(perc, 0, 100, MIN, MAX);

    if (targetPos != this->lastMotorPos) {
        this->lastMotorPos = targetPos;
        this->hardware.setMotorPosition(targetPos);
        this->hardware.printValveValue(perc);
        this->context.setResponse(String(perc));
    }
}
