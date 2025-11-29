#include "tasks/ObserverTask.h"

Observer::ObserverTask::ObserverTask(Context *ctx, Predicate pred, Function fn, int period) : context(ctx), predicate(pred), function(fn) {
    Task::init(period);
}

void Observer::ObserverTask::tick() {
    if ((this->context->*predicate)() && this->function) {
        this->function();
    }
}
