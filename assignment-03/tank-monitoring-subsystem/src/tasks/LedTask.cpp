#include <Arduino.h>
#include <Led.h>

#include "tasks/LedTask.h"

#include "config.h"

extern bool working;

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
