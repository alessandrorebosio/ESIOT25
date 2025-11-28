#include "tasks/NotificationTask.h"
#include <Arduino.h>

namespace Notification {

NotificationTask::NotificationTask(String *str, const bool &enabled, void (*callback)(void), int period)
  : str(str), enabled(enabled), callback(callback) {
  Task::init(period);
}

void NotificationTask::tick() {
  if (enabled && str != nullptr) {
      Serial.println(*str);
      if (callback) {
          callback();
      }
  }
}

} // namespace Notification
