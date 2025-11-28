#pragma once

#include "Task.h"

namespace Notification {

class NotificationTask final : public Task {
  private:
    String *str;
    const bool &enabled;
    void (*callback)(void);

  public:
    explicit NotificationTask(String *str, const bool &enabled, void (*callback)(void), int period);

    void tick() override;

    ~NotificationTask() = default;
};

} // namespace Notification
