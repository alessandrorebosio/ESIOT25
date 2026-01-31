#pragma once

#include "Task.h"
#include "core/Context.h"

#include <Motor.h>
#include <Potentiometer.h>

/**
 * @brief Valve control task for managing motorized valve position
 * 
 * The task executes periodically to continuously monitor and adjust
 * the valve position based on system requirements.
 */
class ValvTask final : public Task {
  private:
    Motor &motor;
    Potentiometer &pot;
    Context &context;

  public:
    /**
     * @brief Construct a new ValvTask object
     * 
     * @param motor Reference to Motor object for valve control
     * @param pot Reference to Potentiometer object for position sensing
     * @param ctx Reference to shared Context for system data
     * @param period Task execution period in milliseconds
     */
    explicit ValvTask(Motor &motor, Potentiometer &pot, Context &ctx, int period);

    /**
     * @brief Execute one iteration of the valve control task
     */
    void tick(void) override;

    /**
     * @brief Destroy the ValvTask object
     * 
     * Cleans up hardware and state objects to prevent memory leaks.
     * Stops the motor and releases any acquired resources.
     */
    ~ValvTask() = default;
};
