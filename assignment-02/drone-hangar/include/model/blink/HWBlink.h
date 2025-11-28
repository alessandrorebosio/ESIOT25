#pragma once

#include <Led.h>

class HWBlink final {
  private:
  Led &led;

  public:
    explicit HWBlink(Led &led);

    void turnOn();

    void turnOff();

    ~HWBlink() = default;
};
