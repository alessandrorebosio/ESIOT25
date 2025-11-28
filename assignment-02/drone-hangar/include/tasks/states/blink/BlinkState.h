#pragma once

namespace Blink {
class BlinkTask;
}

class Led;

namespace Blink {

class BlinkState {
  public:
    virtual void onEnter(BlinkTask &task, Led &led, const bool &enabled) = 0;

    virtual void onExit(BlinkTask &task, Led &led, const bool &enabled) = 0;

    virtual void tick(BlinkTask &task, Led &led, const bool &enabled) = 0;

    virtual ~BlinkState() = default;
};

} // namespace Blink
