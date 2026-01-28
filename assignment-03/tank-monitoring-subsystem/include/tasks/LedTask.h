#pragma once

#include "Task.h"

/**
 * @brief Task responsible for controlling LED indicators based on system status.
 *
 * This task manages two LEDs (green and red) to indicate the system's working state.
 * The green LED is turned on when the system is working, and the red LED is turned on
 * when the system is not working.
 */
class LedTask : public Task {
  public:
    /**
     * @brief Main execution function for the LED control task.
     *
     * This static function is intended to be used as a FreeRTOS task entry point.
     * It initializes two Led objects and enters an infinite loop where it checks
     * the global working flag and updates the LED states accordingly every 100ms.
     *
     * @param parameter Pointer to task parameters (unused in this implementation).
     */
    static void exec(void *parameter);
};
