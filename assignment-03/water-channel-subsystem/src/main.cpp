#include <Arduino.h>

#include "core/Context.h"
#include "core/Scheduler.h"
#include "model/Hardware.h"

#include "tasks/CommunicationTask.h"
#include "tasks/SystemTask.h"
#include "tasks/ValveTask.h"

#include "config.h"

static Hardware hardware(BUTTON_PIN, SERVO_PIN, POT_PIN, LCD_ADDR, LCD_COLS, LCD_ROWS);
static Scheduler scheduler;
static Context context;

void setup(void) {
    scheduler.init(100);
    hardware.init();

    scheduler.addTask(new SystemTask(hardware, context, 250));
    scheduler.addTask(new ValveTask(hardware, context, 100));
    scheduler.addTask(new CommunicationTask(hardware, context, BAUD, 100));
}

void loop(void) {
    scheduler.schedule();
}
