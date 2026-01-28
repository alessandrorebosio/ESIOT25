#pragma once

#include "Task.h"

/**
 * @brief Task responsible for monitoring water level using a sonar sensor.
 *
 * This task continuously reads the distance from the sonar sensor
 * and updates the global waterLevel variable at a specified frequency.
 * The task runs only when the system is in working state.
 */
class MonitoringTask : public Task {
  public:
    /**
     * @brief Main execution function for the monitoring task.
     *
     * This static function is intended to be used as a FreeRTOS task entry point.
     * It initializes a Sonar object and enters a loop where it reads the water
     * level distance at intervals defined by updateFrequency, updating the
     * global waterLevel variable.
     *
     * @param parameter Pointer to task parameters (unused in this implementation).
     */
    static void exec(void *parameter);
};
