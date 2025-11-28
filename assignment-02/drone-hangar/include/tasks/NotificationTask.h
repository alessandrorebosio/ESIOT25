#pragma once

#include "Task.h"

namespace Notification {

class NotificationTask final : public Task {
  private:
    const bool &enabled;
    void (*send)(void);
    void (*callback)(void);

  public:
    explicit NotificationTask(const bool &enabled, void (*send)(void), void (*callback)(void), int period);

    void tick() override;

    ~NotificationTask() = default;
};

} // namespace Notification
