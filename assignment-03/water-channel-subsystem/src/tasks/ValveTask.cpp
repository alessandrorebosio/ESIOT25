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
    uint8_t perc = this->lastPerc;
    int potRaw = this->hardware.getPotValue();

    if (this->context.isAutomatic() || this->context.isVirtualPerc()) {
        perc = this->context.getMotorPerc();
    } else if (abs((int)potRaw - (int)this->lastPotValue) > 10) {
        perc = map(potRaw, 0, 1023, 0, 100);
        this->lastPotValue = potRaw;
    }

    uint8_t targetPos = map(perc, 0, 100, MIN, MAX);

    if (perc != this->lastPerc) {
        this->lastPerc = perc;
        this->hardware.setMotorPosition(targetPos);
        this->hardware.printValveValue(perc);
        this->context.setResponse(String(perc));
    }
}
