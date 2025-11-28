#pragma once

namespace Blink {
class BlinkTask;
}

class HWBlink;

namespace Blink {

class BlinkState {
  public:
    virtual void onEnter(BlinkTask &task, HWBlink &hw, const bool &enabled) = 0;

    virtual void onExit(BlinkTask &task, HWBlink &hw, const bool &enabled) = 0;

    virtual void tick(BlinkTask &task, HWBlink &hw, const bool &enabled) = 0;

    virtual ~BlinkState() = default;
};

} // namespace Blink
