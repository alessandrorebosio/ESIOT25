#include "tasks/ValveTask.h"

#define MIN 0
#define MAX 90

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
    uint8_t pos = 0;
    if (this->context.isAutomatic()) {
        pos = map(this->context.getPosition(), MIN, 100, MIN, MAX);
    } else {
        pos = map(this->hardware.getPotValue(), MIN, 1023, MIN, MAX);
    }

    this->hardware.setMotorPosition(pos);
    this->hardware.printValveValue(pos);
}