#include <Arduino.h>

#include "core/Context.h"
#include "core/Scheduler.h"
#include "model/Hardware.h"

#include "tasks/ObserverTask.h"
#include "tasks/SystemTask.h"
#include "tasks/ValvTask.h"

#include "config.h"

static Hardware hardware(BUTTON_PIN, SERVO_PIN, POT_PIN, LCD_ADDR, LCD_COLS, LCD_ROWS);
static Scheduler scheduler;
static Context context;

void setup(void) {
    scheduler.init(100);
    hardware.init();
    context.reset();

    scheduler.addTask(new SystemTask(hardware.getButton(), context, 250));

    scheduler.addTask(new ValvTask(hardware.getMotor(), hardware.getPotentiometer(), context, 100));

    /**
     * @brief Observer task for printing system and drone states.
     * Period: 500ms
     * Updates LCD display..
     */
    scheduler.addTask(new ObserverTask(
        context.shouldPrint(),
        [] {
            String sys = context.shouldPrintAutomatic() ? "AUTOMATIC" : context.shouldPrintManual() ? "MANUAL" : nullptr;

            if (sys) {
                hardware.getLcd().print(0, "MODE: " + sys);
            }

            context.printDone();
        },
        500));
}

void loop(void) {
    scheduler.schedule();
}
