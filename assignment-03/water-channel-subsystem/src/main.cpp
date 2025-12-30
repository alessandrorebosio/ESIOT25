#include <Arduino.h>

#include "core/Context.h"
#include "core/Scheduler.h"
#include "model/Hardware.h"

#include "config.h"

static Hardware hardware(BUTTON_PIN, SERVO_PIN, POT_PIN, LCD_ADDR, LCD_COLS, LCD_ROWS);
static Scheduler scheduler;
static Context context;

void setup() {
    scheduler.init(100);
    hardware.init();

    scheduler.addTask(NULL);
}

void loop() {
    scheduler.schedule();
}
