#include "tasks/ValveTask.h"

/**
 * @brief Initialize valve control task
 */
ValveTask::ValveTask(Hardware &hw, Context &ctx, int period) : hardware(hw), context(ctx) {
    Task::init(period);
}

/**
 * @brief Periodically control valve position based on mode
 *
 * Manual mode: potentiometer sets position
 * Automatic mode: context target sets position
 * Converts percentage (0-100%) to motor degrees (0-90°)
 */
void ValveTask::tick(void) {
    uint8_t perc = 0;
    if (this->context.isAutomatic()) {
        perc = this->context.getPosition();
    } else {
        perc = map(this->hardware.getPotValue(), 0, 1023, 0, 100);
    }

    this->hardware.setMotorPosition(perc);
    this->hardware.printValveValue(perc);
}