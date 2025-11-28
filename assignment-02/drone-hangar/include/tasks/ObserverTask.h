#pragma once

#include "core/Context.h"

#include "Task.h"

namespace Observer {

typedef bool (Context::*Predicate)();
typedef void (*Function)();

class ObserverTask final : public Task {
  private:
    Context *context;
    Predicate predicate;
    Function function;

  public:
    explicit ObserverTask(Context *ctx, Predicate pred, Function fn, int period);

    void tick() override;

    ~ObserverTask() = default;
};

} // namespace Observer
