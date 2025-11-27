#pragma once

#include <Button.h>
#include <Led.h>
#include <TMP36.h>

class HWSystem final {
  private:
    Button &button;
    Led &led;
    TMP36 &temp;

  public:
    explicit HWSystem(Button &btn, Led &led, TMP36 &sensor);

    bool isPressed();

    void turnOnLed();

    void turnOffLed();

    float temperature();

    ~HWSystem() = default;
};
