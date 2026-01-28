#include <Arduino.h>
#include <Led.h>

#include "tasks/LedTask.h"

#include "config.h"

extern bool working; ///< Global flag indicating if the system is working

/**
 * @brief Implementation of the LED task execution function.
 *
 * This function runs in a FreeRTOS task and continuously monitors the
 * global working flag to control the status LEDs. The task runs on Core 0.
 *
 * @param parameter Task parameters (not used).
 */
void LedTask::exec(void *parameter) {
    Led green(GREEN_LED);
    Led red(RED_LED);

    while (true) {
        if (working) {
            green.on();
            red.off();
        } else {
            green.off();
            red.on();
        }
        delay(100);
    }
}
