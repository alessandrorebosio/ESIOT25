#include <Arduino.h>

#include "core/MsgService.h"
#include "core/Scheduler.h"

#include "model/Context.h"
#include "model/HWPlatform.h"

#include "tasks/BlinkingTask.h"
#include "tasks/HangarControlTask.h"

#include "config.h"

Scheduler scheduler;

void setup() {
    Context *context = new Context();
    MsgSerivce *msg = new MsgSerivce(BAUD);

    scheduler.init(BASEPERIOD);

    scheduler.addTask(new HangarControlTask(msg, context, BASEPERIOD * 10));
}

void loop() {
    scheduler.schedule();
}
