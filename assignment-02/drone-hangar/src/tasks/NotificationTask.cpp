#include "tasks/NotificationTask.h"

namespace Notification {

NotificationTask::NotificationTask(const bool &enabled, void (*send)(void), void (*callback)(void), int period)
    : enabled(enabled), send(send), callback(callback) {
    Task::init(period);
}

void NotificationTask::tick() {
    if (enabled) {
        if (send) {
            send();
        }
        if (callback) {
            callback();
        }
    }
}

} // namespace Notification
