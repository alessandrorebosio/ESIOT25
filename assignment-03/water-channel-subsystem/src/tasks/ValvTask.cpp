#include "tasks/ValvTask.h"

/**
 * @brief Initialize valve control task
 */
ValvTask::ValvTask(Motor &motor, Potentiometer &pot, Context &ctx, int period) 
    : motor(motor), pot(pot), context(ctx) {
    Task::init(period);
    this->motor.on();
}

/**
 * @brief Periodically control valve position based on mode
 * 
 * Manual mode: potentiometer sets position
 * Automatic mode: context target sets position
 * Converts percentage (0-100%) to motor degrees (0-90°)
 */
void ValvTask::tick() {
    float targetOpening = 0.0;

    if (!context.isAutomatic()) {
        int potVal = pot.read(); 
        targetOpening = (potVal / 1023.0) * 100.0;
        context.setValveOpening(targetOpening);
    } else {
        targetOpening = context.getValveOpening();
    }

    uint8_t targetDegrees = static_cast<uint8_t>(targetOpening * 0.9);
    this->motor.setPosition(targetDegrees);
}
