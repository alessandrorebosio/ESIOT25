#include "tasks/HangarControlTask.h"

#include "config.h"

#define LANDING_MSG "landing"
#define TAKEOFF_MSG "takeoff"

HangarControlTask::HangarControlTask(MsgSerivce *msg, Context *context)
    : msg(msg), context(context) {
}

HangarControlTask::HangarControlTask(MsgSerivce *msg, Context *context,
                                     int period)
    : HangarControlTask(msg, context) {
    this->init(period);
}

void HangarControlTask::init(int period) {
    Task::init(period);
}

void HangarControlTask::tick() {
}
